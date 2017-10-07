#include "Server.hpp"
#include "tcpClient.hpp"
#include <string.h>
#include <boost/asio/ssl.hpp>

typedef boost::asio::ssl::stream<boost::asio::ip::tcp::socket> ssl_socket;

tcpClient::tcpClient(boost::asio::io_service& io_service, boost::asio::ssl::context& context) : m_socket(io_service, context)
{
}

ssl_socket::lowest_layer_type& tcpClient::socket()
{
	return m_socket.lowest_layer();
}

void tcpClient::start()
{
	m_socket.async_handshake(boost::asio::ssl::stream_base::server, boost::bind(&tcpClient::handle_handshake, this, boost::asio::placeholders::error));
}
void tcpClient::handle_handshake(const boost::system::error_code& error)
{
	if (!error)
	{
		std::cout << "handle_handshake" << std::endl;
		boost::asio::async_read(m_socket, boost::asio::buffer(this->buffer), boost::asio::transfer_at_least(1), boost::bind(&tcpClient::handle_read, this, boost::asio::placeholders::error));
	}
	else
	{
		std::cout << error.message() << std::endl;
	} 
}

void tcpClient::handle_read(const boost::system::error_code& error)
{
	if (!error)
	{
		std::cout << this->buffer.data() << std::endl;
		this->buffer.assign(0);
		boost::asio::async_read(m_socket, boost::asio::buffer(this->buffer), boost::asio::transfer_at_least(1), boost::bind(&tcpClient::handle_read, this, boost::asio::placeholders::error));
	}
	else
	{
		std::cout << error.message() << std::endl;
	} 
}

void tcpClient::handle_write(const boost::system::error_code& error)
{
	if (!error)
	{
	}
	else
	{
		std::cout << error.message() << std::endl;
	} 
}
