//
// parser.hpp for parser in /home/abachelet/Documents/test/cpp_spider/includes
// 
// Made by Adrien Bachelet
// Login   <adrien.bachelet@epitech.eu>
// 
// Started on  Fri Oct  6 15:11:52 2017 Adrien Bachelet
// Last update Sat Oct  7 20:03:12 2017 Adrien Bachelet
//

#ifndef		PARSER_HPP
# define	PARSER_HPP

# include	<iostream>
# include	<fstream>
# include	<sstream>
# include	<string>
# include	<map>

class		Parser
{
public:
  Parser();
  ~Parser();
  void		parseInput(std::string input);
  typedef	std::string (Parser::*option)(std::istringstream *);

private:
  std::string	connect(std::istringstream *input);
  std::string	keyboard(std::istringstream *input);
  std::string	mouse(std::istringstream *input);
  std::string	ok(std::istringstream *input);
  bool		check_num(std::string str);
  bool		writeInFile(std::string file, std::string data);

  std::string	id = "";
  std::map<std::string, option>	keywords;
};

#endif		/* _!PARSER_HPP_ */
