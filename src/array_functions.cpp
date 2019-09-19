/*arrray_functions.cpp
 *
 *Elliott Armstrong -- elliott.armstrong.17@cnu.edu
 *Version 16.09.2019
 *
 */

//============================================================================
//	TODO add necessary includes here
#include "array_functions.h"
#include "constants.h"
#include "utilities.h"
#include <array>
#include <fstream>
#include <iostream>
#include <string>
#include <sstream>
using namespace std;
//============================================================================

//============================================================================
//	stuff you will need
//============================================================================
//TODO define a structure to track words and number of times they occur
struct entry
{
	string word;
	int num_occurances;
};

//TODO add a global array of entry structs (global to this file)

//TODO add variable to keep track of next available slot in array



//TODO define all functions in header file

//Zero out array that tracks words and their occurances
void clearArray(){
	return;
}

//How many unique words are in array
int getArraySize(){
return -1;
}

//Get data at a particular location
std::string getArrayWordAt(int i){
	return "";
}
int getArrayWord_NumbOccur_At(int i){
	return 0;
}

/*Loop through whole file, one line at a time
 * call processLine on each line
 * returns false: myfstream is not open
 *         true: otherwise*/
bool processFile(std::fstream &myfstream){
	return false;
}


/*Take 1 line and extract all the tokens from it
feed each token to processToken for recording*/
void processLine(std::string &myString){
	return;
}

//Keep track of how many times each token seen
void processToken(std::string &token){
	return;
}


/*If you are debugging the file must be in the project parent directory
  in this case Project2 with the .project and .cProject files*/
bool openFile(std::fstream& myfile, const std::string& myFileName,
		std::ios_base::openmode mode){
	return false;
}

//Iff myfile is open then close it
void closeFile(std::fstream& myfile){
	return;
}

/* Serializes all content in myEntryArray to file outputfilename
 * Returns  FAIL_FILE_DID_NOT_OPEN if cannot open outputfilename
 * 			FAIL_NO_ARRAY_DATA if there are 0 entries in myEntryArray
 * 			SUCCESS if all data is written and outputfilename closes OK
 * */
int writeArraytoFile(const std::string &outputfilename){
	return -1;
}

/*
 * Sort myEntryArray based on so enum value.
 * You must provide a solution that handles alphabetic sorting (A-Z)
 * The presence of the enum implies a switch statement based on its value
 */
void sortArray(constants::sortOrder so){
	return;
}


//TODO look in utilities.h for useful functions, particularly strip_unwanted_chars!
