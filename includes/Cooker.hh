//
// Cooker.hh for cpp_plazza in /home/patoche/rendu/CPP/cpp_plazza/includes
//
// Made by Hugo Prenat
// Login   <prenat_h@epitech.eu>
//
// Started on  Thu Apr 16 17:09:52 2015 Hugo Prenat
// Last update Wed Apr 22 15:35:53 2015 Jean-Baptiste Grégoire
//

#ifndef COOKER_HH_
# define COOKER_HH_

# include <string>
# include "Kitchen.hh"

class	Cooker
{
 public:
  Cooker(Kitchen *kitchen);
  ~Cooker();

public:
  bool	createPizza(APizza const *pizza);

private:
  enum	Action
    {
      CHECK = 0,
      GET
    };

private:
  bool	manageIngredient(APizza const *pizza, enum Action action);

private:
  Kitchen	*_kitchen;
};

#endif // !COOKER_HH_
