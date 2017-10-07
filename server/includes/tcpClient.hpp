#ifndef TCPCLIENT_HPP
# define TCPCLIENT_HPP

#include <boost/asio/ssl.hpp>
#include "Server.hpp"

typedef boost::asio::ssl::stream<boost::asio::ip::tcp::socket> ssl_socket;

class tcpClient :  public boost::enable_shared_from_this<tcpClient>
{
public:
	typedef boost::shared_ptr<tcpClient> pointer;

	tcpClient(boost::asio::io_service& io_service, boost::asio::ssl::context& context);
	ssl_socket::lowest_layer_type& socket();
	static pointer create(boost::asio::io_service& );
	void start();
	void read();
	void write();
	void handle_read(const boost::system::error_code&);
	void handle_write(const boost::system::error_code&);
	void handle_handshake(const boost::system::error_code&);
	ssl_socket m_socket;
	boost::array<char, 2048> buffer;
	std::string m_message;
	std::string hostname;
	std::string version;
};

#endif