#ifndef MONGODB_HPP
#define MONGODB_HPP

#include <iostream>
#include <bsoncxx/builder/stream/document.hpp>
#include <bsoncxx/json.hpp>
#include <mongocxx/client.hpp>
#include <mongocxx/instance.hpp>

class mongodb
{
public:
  mongodb();
  ~mongodb();
  void insertDoc(std::string, std::string);
	
private:
  mongocxx::client *conn;
  mongocxx::database	db;
};

#endif
