#ifndef SCAVTRAP_HPP
#define SCAVTRAP_HPP

#include <iostream>
#include "ClapTrap.hpp"

#include <iostream>
#include "ClapTrap.hpp"

class	ScavTrap: public ClapTrap
{
	public :
		ScavTrap(const std::string name);
		ScavTrap(const ScavTrap & ct);
		~ScavTrap(void);

		ScavTrap &	operator=(const ScavTrap & rhs);

		void	attack(const std::string & target);
		void	guardGate(void);

	private:
		ScavTrap(void);
};

#endif