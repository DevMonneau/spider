//
// inputParser.hpp for inputParser in /home/abachelet/Documents/Rendu/cpp_spider/server/includes
// 
// Made by Adrien Bachelet
// Login   <adrien.bachelet@epitech.eu>
// 
// Started on  Fri Oct  6 11:02:06 2017 Adrien Bachelet
// Last update Fri Oct  6 11:06:36 2017 Adrien Bachelet
//

#ifndef			INPUTPARSER_HPP
# define		INPUTPARSER_HPP

class			inputParser
{
public:
  inputParser(std::string m_message);
  ~inputParser();

private:
  void			token();
};

#endif			/* _INPUTPARSER_HPP_ */
