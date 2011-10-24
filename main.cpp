
#include <iostream>
#include <boost/asio.hpp>

using boost::asio::ip::tcp;

int main(int argc, char* argv[]) {

	try {
		boost::asio::io_service io_service;

	    tcp::resolver resolver(io_service);
    	tcp::resolver::query query(tcp::v4(), "www.leaiva.com", "80");
    	tcp::resolver::iterator endpoint_iterator = resolver.resolve(query);
	    tcp::resolver::iterator end;

	    tcp::socket socket(io_service);
	    boost::system::error_code error = boost::asio::error::host_not_found;
	    
	    while(error && endpoint_iterator != end) {
	    	
	    	socket.close();
	    	socket.connect(*endpoint_iterator++, error);
	    }

	    if(error) {
	    	throw boost::system::system_error(error);
	  	}


	}
	catch(std::exception& e) {
    	std::cerr << e.what() << std::endl;
  	}
	
  	return 0;
}
