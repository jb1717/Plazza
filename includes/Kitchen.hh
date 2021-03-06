//
// Kitchen.hh for cpp_plazza in /home/patoche/rendu/CPP/cpp_plazza
//
// Made by Hugo Prenat
// Login   <prenat_h@epitech.eu>
//
// Started on  Fri Apr 17 15:27:59 2015 Hugo Prenat
// Last update Sun Apr 26 07:22:37 2015 David Tran
//

#ifndef KITCHEN_HH_
# define KITCHEN_HH_

# include <iostream>
# include <string>
# include <vector>
# include <map>
# include <ctime>

# include "Pizza.hh"
# include "ThreadPool.hh"
# include "NamedPipe.hh"

class					Kitchen
{
public:
  Kitchen(unsigned int nbCooker, float mult, int stock_time);
  ~Kitchen();

public:
  unsigned int				getFreeCooker() const;
  std::vector<Ingredients *> const	*getAvailableIngredients() const;
  float					getPreparationTime() const;
  int					getStockTime() const;

public:
  bool					addOnePizza(Pizza *pizza);
  void					regenIngredients();
  void					run();

private:
  unsigned int				_nbCooker;
  unsigned int				_nbPizza;
  unsigned int				_capacity;
  ThreadPool				_cookers;
  float					_mult;
  int					_stock_time;
  std::vector<Pizza *>			_order;
  std::vector<Ingredients *>		_ingredients;
  std::map<std::string, TypePizza>	_typePizza;
  std::map<std::string, TaillePizza>	_sizePizza;
  std::map<std::string, int>		_timePizza;
  EThread				_regen;
  NamedPipe				*_fromRec;
  NamedPipe				*_toRec;
};

typedef struct
{
  Pizza		*pizza;
  Kitchen	*kitchen;
}		cookerArgs;

void				*startCreatePizza(void *p);
void				*startRegenIngredients(void *p);

#endif // !KITCHEN_HH_
