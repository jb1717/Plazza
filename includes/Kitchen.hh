//
// Kitchen.hh for cpp_plazza in /home/patoche/rendu/CPP/cpp_plazza
//
// Made by Hugo Prenat
// Login   <prenat_h@epitech.eu>
//
// Started on  Fri Apr 17 15:27:59 2015 Hugo Prenat
// Last update Fri Apr 24 03:33:07 2015 Jean-Baptiste Grégoire
//

#ifndef KITCHEN_HH_
# define KITCHEN_HH_

# include <iostream>
# include <string>
# include <vector>

# include "Pizza.hh"
# include "ThreadPool.hh"

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
  bool					addOnePizza(Pizza &pizza);
  void					regenIngredients();

private:
  unsigned int				_nbCooker;
  unsigned int				_nbPizza;
  unsigned int				_capacity;
  ThreadPool				_cookers;
  float					_mult;
  int					_stock_time;
  std::vector<Pizza *>			_order;
  std::vector<Ingredients *>		_ingredients;
  EThread				_regen;
};

typedef struct
{
  Pizza		*pizza;
  Kitchen	*kitchen;
}		cookerArgs;

void				*startCreatePizza(void *p);
void				*startRegenIngredients(void *p);

#endif // !KITCHEN_HH_
