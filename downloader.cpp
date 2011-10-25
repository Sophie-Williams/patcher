
#include "downloader.h"


Downloader::Downloader(std::string _host)
{
		host = _host;
}

void Downloader::get(std::string uri, std::string expected_checksum) 
{
		int last_slash = uri.find_last_of('/');
		std::string local_dir = uri.substr(0, last_slash);
		std::string filename = uri.substr(last_slash + 1);

		// Find host using boost
		tcp::resolver resolver(io_service);
    tcp::resolver::query query(tcp::v4(), host, "80");
    tcp::resolver::iterator endpoint_iterator = resolver.resolve(query);
		tcp::resolver::iterator end;

		tcp::socket socket(io_service);
		error = boost::asio::error::host_not_found;
	
		// Connect socket to host
		while(error && endpoint_iterator != end) {
	    	socket.close();
	    	socket.connect(*endpoint_iterator++, error);
		}

		if(error) {
		    throw boost::system::system_error(error);
		}

		// Build request
	  std::stringstream request;
	  request << "GET " + uri + " HTTP/1.0 \r\n";
	  request << "Host: " << host << "\r\n";
	  request << "\r\n";

	 	// Make request
		boost::system::error_code ignored_error;
		boost::asio::write(socket, boost::asio::buffer(request.str()), boost::asio::transfer_all(), ignored_error);

		// Read response
		char buf[1024];
		size_t len = socket.read_some(boost::asio::buffer(buf), error);
		if (error == boost::asio::error::eof) {
				return; 
		}
		else if (error) {
				throw boost::system::system_error(error);
		}

		// Parse out the headers
		std::string response = buf;
		response = response.substr(response.find("\r\n\r\n") + 4);

		FileManager::mkdirs("tmp" + local_dir);

		std::string tmp_path = "tmp" + uri;
		FileManager::write(response, tmp_path);

		std::cout << tmp_path << "  " << FileManager::checksum(tmp_path) << "\n";

		if(!expected_checksum.empty()) {
				
		}

		local_dir = "./data" + local_dir;
		FileManager::mkdirs(local_dir);
		FileManager::mv(tmp_path, local_dir + filename);
}
