//
// Reception.hh for Plazza in /home/jibb/rendu/cpp_plazza/includes
//
// Made by Jean-Baptiste Grégoire
// Login   <jibb@epitech.net>
//
// Started on  Fri Apr 17 16:28:27 2015 Jean-Baptiste Grégoire
// Last update Fri Apr 17 22:35:44 2015 Hugo Prenat
//

#ifndef RECEPTION_HH_
# define RECEPTION_HH_

# include <iostream>
# include <string>
# include <curses.h>

class	Reception
{
public:
  Reception(float mult, int nb_cooker, int stock_time);

  bool			launchUI();
  std::string const	&getInput() const;
  void			getOutput() const;
  bool			manageOrder() const;

  ~Reception();

private:

  void			parseOrder() const;

private:
  float			_mult;
  int			_nb_cooker;
  int			_stock_time;
  WINDOW	*_screen;
  WINDOW	*_output;
  WINDOW	*_input;
  int			_win_x;
  int			_win_y;
};

#endif // !RECEPTION_HH_
