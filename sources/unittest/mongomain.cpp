#include "../../includes/mongodb.hpp"

int main()
{
	mongodb test;
	test.insertDoc("titi", "password");
	test.insertDoc("toto", "toto@live.fr");
	test.insertDoc("toto", "le mdp de louis");
	test.insertDoc("lol", "qaund tu reussis ta db :)");
	test.insertDoc("tata", "cest bon easy module de francais");	
}