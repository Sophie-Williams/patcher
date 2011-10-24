
#include "downloader.h"


Downloader::Downloader(std::string _host)
{
	host = _host;
}

void Downloader::get(std::string uri, std::string local_path, std::string expected_checksum) 
{
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

	FileManager::makedir("tmp");
	FileManager::write(response, "tmp/foo.txt");
	//FileManager::rmdir("tmp");

}


std::string Downloader::get_checksum(std::string file) 
{
	
}