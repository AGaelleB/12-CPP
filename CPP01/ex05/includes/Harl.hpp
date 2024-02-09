#ifndef HARL_HPP
#define HARL_HPP

#include <iostream>

#define MSG_LEVEL "choose a level between \"DEBUG\", \"INFO\", \"WARNING\" and \"ERROR\""
#define MSG_DEBUG "I love having extra bacon for my 7XL-double-cheese-triple-pickle-special-ketchup burger. I really do !"
#define MSG_INFO "I cannot believe adding extra bacon costs more money. You didn’t put enough bacon in my burger ! If you did, I wouldn’t be asking for more !"
#define MSG_WARNING "I think I deserve to have some extra bacon for free. I’ve been coming for years whereas you started working here since last month."
#define MSG_ERROR "This is unacceptable ! I want to speak to the manager now."

class Harl {

	private :
		void	_debug(void);
		void	_info(void);
		void	_warning(void);
		void	_error(void);

	public :
		Harl();
		~Harl();
		void	complain(std::string level);
};

// Définition d'une struct pour associer un niveau à une fonction membre
typedef struct s_level {
	std::string level;
	void (Harl::*function)();
} t_level;

#endif
