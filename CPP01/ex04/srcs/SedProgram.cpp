#include "../includes/SedProgram.hpp"

#include <iostream>
#include <fstream>
#include <string>
#include <cstdlib>


/* 
	Le <filename> sera ouvert et son contenu copié dans un nouveau fichier
	<filename>.replace, où chaque occurrence de s1 sera remplacée par s2.
 */

/********************************* CONST ET DEST **********************************/

SedProgram::SedProgram() {

}

SedProgram::~SedProgram() {

}


/************************************ FONCTIONS ************************************/

// pour verifier si le fichier a copier est existant
void	SedProgram::checkFilename(std::string fileName) {

	std::ifstream file(fileName.c_str());

	if (file.is_open()) {
		file.close();
	}
	else {
		std::cout << "Error: filename doesn't exist" << std::endl;
		std::exit(0);
	}

}

// pour creer le futur fichier "<filename>.replace" et ecrire dedans
std::string SedProgram::createNewFilename(std::string fileName) {

	std::string newFileName = fileName + ".replace";
	std::ofstream newFile(newFileName.c_str()); // Utilisez c_str() pour obtenir un const char*

	if (newFile.is_open()) {
		newFile.close();
		return newFileName;
	}
	else {
		std::cout << "Error: unable to create the newfile" << std::endl;
		std::exit(0);
	}
}


// parcours le file avec getline et copie et remplace en envoyant dans le newfileName
void	SedProgram::checkAndRreplace(std::string fileName, std::string s1, std::string s2) {
	
	std::string outputFileName;
	outputFileName = createNewFilename(fileName);

	std::ifstream inputFile(fileName.c_str());
	std::ofstream outputFile(outputFileName.c_str()); 

	std::string readLine;

	while (std::getline(inputFile, readLine)) {
		size_t pos = 0;
		while ((pos = readLine.find(s1, pos)) != std::string::npos) {
			// Remplacez s1 par s2 dans la ligne
			readLine = readLine.substr(0, pos) + s2 + readLine.substr(pos + s1.length());
			pos += s2.length(); // Avancez la position après la substitution
		}
		// Écrivez la ligne modifiée dans le fichier de sortie
		outputFile << readLine << std::endl;
	}
	inputFile.close();
	outputFile.close();
}
