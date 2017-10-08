#include "mongodb.hpp"

mongodb::mongodb()
{
      mongocxx::instance instance{};
      this->conn = new mongocxx::client(mongocxx::uri{"mongodb://37.59.125.25:27017"});
      this->db = (*conn)["spider"];
}

mongodb::~mongodb()
{
  delete this->conn;
}

void mongodb::insertDoc(std::string hostname, std::string data)
{
 	bsoncxx::builder::stream::document doc{};
	mongocxx::collection coll;
	coll = db[hostname];
	doc << "hostname" << hostname;
	doc << "data" << data;
	coll.insert_one(doc.view());
}

