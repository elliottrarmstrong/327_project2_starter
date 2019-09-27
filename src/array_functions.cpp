/*arrray_functions.cpp
 *
 *Elliott Armstrong -- elliott.armstrong.17@cnu.edu
 *Version 27.09.2019
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
using namespace constants;
//============================================================================

//the definition of the entry structure
struct entry
{
	string word;
	int num_occurances;
};

//An array of type entry
entry words[MAX_WORDS];

//A variable to keep track of the next available slot
int next_slot = 0;

//Zero out array that tracks words and their occurances
void clearArray(){
	for(int i = 0; i < MAX_WORDS; i++){
		words[i].word = "";
		words[i].num_occurances = 0;
	}
	next_slot = 0;
	return;
}

//How many unique words are in array
int getArraySize(){
	return next_slot;
}

//Get data at a particular location
std::string getArrayWordAt(int i){
	return words[i].word;
}
int getArrayWord_NumbOccur_At(int i){
	return words[i].num_occurances;
}

/*Loop through whole file, one line at a time
 * call processLine on each line
 * returns false: myfstream is not open
 *         true: otherwise*/
bool processFile(std::fstream &myfstream){
	std::string line;
	if(myfstream.is_open()){
		while(!myfstream.eof()){
			getline(myfstream, line);
			processLine(line);
		}

		return true;
	}
	return false;
}


/*Take 1 line and extract all the tokens from it
feed each token to processToken for recording*/
void processLine(std::string &myString){
	stringstream ss(myString);
	string tempToken;
	while(getline(ss, tempToken, CHAR_TO_SEARCH_FOR)){
		processToken(tempToken);
	}
	return;
}

//Keep track of how many times each token seen
void processToken(std::string &token){
	bool seen = false;
	std::string tempword;
	std::string temptoken;
	strip_unwanted_chars(token);

	if(token == ""){
		return;
	}

	for(int j = 0; j < next_slot; j++){
		tempword = words[j].word;
		toUpper(tempword);
		temptoken = token;
		toUpper(temptoken);
		if(tempword == temptoken){
			seen = true;
			words[j].num_occurances++;
		}
	}

	if(!seen){
		words[next_slot].word = token;
		words[next_slot].num_occurances++;
		next_slot++;
	}

	return;
}


/*If you are debugging the file must be in the project parent directory
  in this case Project2 with the .project and .cProject files*/
bool openFile(std::fstream& myfile, const std::string& myFileName,
		std::ios_base::openmode mode){
	myfile.open(myFileName, mode);
	if(myfile.is_open()){
		return true;
	}
	return false;
}

//If myfile is open then close it
void closeFile(std::fstream &myfile){
	if(myfile.is_open()){
		myfile.close();
	}
	return;
}

/* Serializes all content in myEntryArray to file outputfilename
 * Returns  FAIL_FILE_DID_NOT_OPEN if cannot open outputfilename
 * 			FAIL_NO_ARRAY_DATA if there are 0 entries in myEntryArray
 * 			SUCCESS if all data is written and outputfilename closes OK
 * */
int writeArraytoFile(const std::string &outputfilename){
	ofstream outputfile;
	outputfile.open(outputfilename.c_str());

	if(!outputfile.is_open()){
		return FAIL_FILE_DID_NOT_OPEN;
	}


	if(next_slot == 0){
		return FAIL_NO_ARRAY_DATA;
	}

	for(int m = 0; m < next_slot; m++){
		outputfile << words[m].word + " " + intToString(words[m].num_occurances) + "\n";
	}
	return SUCCESS;
}

/*
 * Sort myEntryArray based on so enum value.
 * You must provide a solution that handles alphabetic sorting (A-Z)
 * The presence of the enum implies a switch statement based on its value
 */
void sortArray(constants::sortOrder so){
	switch(so){
		case ASCENDING:
			for(int k = 0; k < next_slot-1; k++){
				if(words[k].word > (words[k+1].word)){
					entry tmp;
					tmp.num_occurances = 0;
					tmp.word = "";
					tmp.word = words[k].word;
					tmp.num_occurances = words[k].num_occurances;
					words[k].word = words[k+1].word;
					words[k].num_occurances = words[k+1].num_occurances;
					words[k+1].word = tmp.word;
					words[k+1].num_occurances = tmp.num_occurances;
					k = 0;
				}
			}
			break;
		case DESCENDING:
			break;
		case NUMBER_OCCURRENCES:
			break;
		case NONE:
			break;
	}
}


//TODO look in utilities.h for useful functions, particularly strip_unwanted_chars!
