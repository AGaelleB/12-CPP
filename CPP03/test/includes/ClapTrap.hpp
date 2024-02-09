
#ifndef CLAPTRAP_HPP
# define CLAPTRAP_HPP

#include <iostream>

class ClapTrap
{
	public:
		ClapTrap(const std::string name);
		ClapTrap(const ClapTrap & src);
		~ClapTrap(void);
		
		ClapTrap &	operator=(ClapTrap const &rhs);

		void	attack(const std::string& target);
		void	takeDamage(unsigned int amount);
		void	beRepaired(unsigned int amount);

	protected:
		ClapTrap(void);

		std::string	_name;
		int			_hit_points;
		int			_energy_points;
		int			_attack_damage;
};

#endif