#include <iostream>
#include <boost/asio.hpp>
#include <boost/asio/ssl.hpp>
#include <boost/array.hpp>
#include <boost/enable_shared_from_this.hpp>

#include "../includes/Server.hpp"

typedef boost::asio::ssl::stream<boost::asio::ip::tcp::socket> ssl_socket;

int main(int ac, char **av)
{
  if (ac < 2)
    {
      std::cout << "Usage: ./server PORT. Merci de ta comprehension enculé!" << std::endl;
      return (-1);
    }
  try
    {
      boost::asio::io_service io_service;
      boost::asio::ssl::context ctx(boost::asio::ssl::context::sslv23);
      ctx.set_verify_mode(boost::asio::ssl::verify_peer);
      ssl_socket sock(io_service, ctx);
      Server server(io_service, atoi(av[1]));
      io_service.run();
    }
  catch (std::exception& e)
    {
      std::cerr << e.what() << std::endl;
    }
  return 0;
}
