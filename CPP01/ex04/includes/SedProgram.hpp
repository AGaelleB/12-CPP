#ifndef SEDPROGRAM
#define SEDPROGRAM

#include <iostream>

class SedProgram {

	private :

	public :
		SedProgram();
		~SedProgram();
		void	checkFilename(std::string fileName);
		std::string	createNewFilename(std::string fileName);
		void	checkAndRreplace(std::string fileName, std::string s1, std::string s2);
};

#endif
