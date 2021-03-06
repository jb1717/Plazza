//
// NamedPipe.hh for Plazza in /home/jibb/rendu/cpp_plazza/src/Encapsulation
//
// Made by Jean-Baptiste Grégoire
// Login   <jibb@epitech.net>
//
// Started on  Mon Apr 20 19:06:26 2015 Jean-Baptiste Grégoire
// Last update Sun Apr 26 08:15:35 2015 Jean-Baptiste Grégoire
//

#ifndef NAMEDPIPE_HH_
# define NAMEDPIPE_HH_

# include <unistd.h>
# include <sys/types.h>
# include <sys/stat.h>
# include <iostream>
# include <sstream>
# include <fstream>
# include "Plazza.hh"

class		NamedPipe
{
public:
  NamedPipe(std::string const &name);
  bool		is_good() const;
  void		operator>>(std::string &str);
  void		operator<<(std::string const &str);
  void		set_good();
  ~NamedPipe();

private:
  std::string const	_name;
  std::ifstream		_ifs;
  std::ofstream		_ofs;
};

#endif // !NAMEDPIPE_HH_
