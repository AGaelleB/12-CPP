#include "../includes/SedProgram.hpp"

#include <iostream>
#include <fstream>
#include <string>
#include <cstdlib>


/********************************* CONST ET DEST **********************************/

SedProgram::SedProgram() {

}

SedProgram::~SedProgram() {

}


/************************************ FONCTIONS ************************************/

void	SedProgram::checkFilename(std::string fileName) {

	std::ifstream file(fileName.c_str());

	if (file.is_open()) {
		file.close();
	}
	else {
		std::cout << "Error: unable to open the file" << std::endl;
		std::exit(0);
	}

}

std::string SedProgram::createNewFilename(std::string fileName) {

	std::string newFileName = fileName + ".replace";
	std::ofstream newFile(newFileName.c_str()); // c_str() pour obtenir un const char*

	if (newFile.is_open()) {
		newFile.close();
		return newFileName;
	}
	else {
		std::cout << "Error: unable to create the newfile" << std::endl;
		std::exit(0);
	}
}

void	SedProgram::checkAndRreplace(std::string fileName, std::string s1, std::string s2) {
	
	std::string outputFileName;
	outputFileName = createNewFilename(fileName);

	std::ifstream inputFile(fileName.c_str());
	std::ofstream outputFile(outputFileName.c_str());

	std::string readLine;
	while (std::getline(inputFile, readLine)) { // Lit une ligne dans readLine

		size_t pos = 0;
		while ((pos = readLine.find(s1, pos)) != std::string::npos) {
			// Trouve la pos de la 1er occurrence de s1 dans la ligne

			// Sépare la ligne en 3 parties : avant, s2, et après la substitution
			std::string partBefore = readLine.substr(0, pos);
			std::string partAfter = readLine.substr(pos + s1.length());

			// Remplace s1 par s2 en concaténant les trois parties
			readLine = partBefore + s2 + partAfter;

			pos += s2.length(); // Avance la pos pour éviter une boucle infinie
		}
		// Écrire la ligne modifiée dans le fichier de sortie
		outputFile << readLine << std::endl;
	}
	inputFile.close();
	outputFile.close();
}
