#include "Server.hpp"
#include "tcpClient.hpp"

Server::Server(boost::asio::io_service& io_service, int port) : io_service_(io_service), m_acceptor(io_service, boost::asio::ip::tcp::endpoint(boost::asio::ip::tcp::v4(), port)), context_(boost::asio::ssl::context::sslv23)
{
	std::cout << "Server Start" << std::endl;
	context_.set_options(
        boost::asio::ssl::context::default_workarounds
        | boost::asio::ssl::context::no_sslv2
        | boost::asio::ssl::context::single_dh_use);
    context_.set_password_callback(boost::bind(&Server::get_password, this));
    context_.use_certificate_chain_file("cert.pem");
    context_.use_private_key_file("key.pem", boost::asio::ssl::context::pem);
    //context_.use_tmp_dh_file("session.pem");
	start_accept();
}

Server::~Server()
{
	std::cout << "Server Stop" << std::endl;
}

std::string Server::get_password()
{
	return "spider";
}

int Server::getPort()
{
	return (this->port);
}

void Server::start_accept()
{
	tcpClient* new_tcpClient = new tcpClient(io_service_, context_);
    m_acceptor.async_accept(new_tcpClient->socket(), boost::bind(&Server::handle_accept, this, new_tcpClient, boost::asio::placeholders::error));
}

void Server::handle_accept(tcpClient* new_tcpClient, const boost::system::error_code& error)
{
	if (!error)
	{
		std::cout << "Reçu un client!" << std::endl;
		new_tcpClient->start();
		start_accept();
	}
}
