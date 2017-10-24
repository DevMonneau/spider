//
// parser.hpp for parser in /home/abachelet/Documents/test/cpp_spider/includes
// 
// Made by Adrien Bachelet
// Login   <adrien.bachelet@epitech.eu>
// 
// Started on  Fri Oct  6 15:11:52 2017 Adrien Bachelet
// Last update Sun Oct  8 19:50:13 2017 Adrien Bachelet
//

#ifndef		PARSER_HPP
# define	PARSER_HPP

# include	<codecvt>
# include	<locale>
# include	<string>
# include	<iostream>
# include	<iostream>
# include	<fstream>
# include	<sstream>
# include	<string>
# include	<map>
# include "mongodb.hpp"

class		Parser
{
public:
  Parser();
  ~Parser();
  void		parseInput(const std::string &input);
  typedef	std::string (Parser::*option)(std::istringstream *);

private:
  std::string connect(std::istringstream *input);
  std::string keyboard(std::istringstream *input);
  std::string mouse(std::istringstream *input);
  std::string ok(std::istringstream *input);
  bool    checkSeparator(const std::string &keys);
  bool    check_num(const std::string &str);
  bool    writeInFile(const std::string &file, std::string data);

  mongodb db;
  std::string	id;
  std::string	word;
  std::map<std::string, option>	keywords;
};

#endif		/* _!PARSER_HPP_ */
