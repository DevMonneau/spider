#ifndef SERVER_HPP
# define SERVER_HPP

#include <iostream>
#include <boost/bind.hpp>
#include <boost/asio.hpp>
#include <boost/asio/ssl.hpp>
#include <boost/array.hpp>
#include <boost/enable_shared_from_this.hpp>
#include "tcpClient.hpp"

typedef boost::asio::ssl::stream<boost::asio::ip::tcp::socket> ssl_socket;

class Server
{
public:
	Server(boost::asio::io_service& io_service, int port);
	~Server();
	int getPort();
	std::string get_password();

private:
	void start_accept();
	void handle_accept(tcpClient*, const boost::system::error_code& error);
	int port;
	boost::asio::io_service& io_service_;
	boost::asio::ip::tcp::acceptor m_acceptor;
	boost::asio::ssl::context context_;
};

#endif
