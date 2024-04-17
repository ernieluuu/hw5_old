#ifndef RECCHECK
// For debugging
#include <iostream>
// For std::remove
#include <algorithm> 
#include <map>
#include <set>
#endif

#include "wordle.h"
#include "dict-eng.h"
using namespace std;


// Add prototypes of helper functions here
void findWords(const std::string& in,
	const std::string& floating,
	const std::set<std::string>& dict,
	std::set<std::string>& potentialWords,
	int currLoc,
	int alphaLoc);

bool isWord(const std::string& word, const std::set<std::string>& dict);

// Definition of primary wordle function
std::set<std::string> wordle(
    const std::string& in,
    const std::string& floating,
    const std::set<std::string>& dict)
{
    // Add your code here

	std::set<std::string> potentialWords; // stores potential matches

	// if empty string
	if (in.size() == 0)
	{
		return;
	}

}

// Define any helper functions here


/*
* 
nvm, scratch all of that
you first generate a set / list of possible words
and then use the find() method of a set (logn) to check
if it is a real word in the english langauge.

check if in[currLoc] == '-' or == alphabet_loc


*/


/*this function recursively generates a set of potential letter combinations*/
void findWords(const std::string& in,
	const std::string& floating,
	const std::set<std::string>& dict,
	std::set<std::string>& potentialWords,
	int currLoc,
	int alphaLoc)
{
	/*
	where currLoc stands for the current location in 'in'
	and alphaLoc stands for the current alphabetical letter that we are on.
	*/

	/*
	if the alphaLoc letter is a floating letter
	pop that letter out of floating letters
	note this is only for when replacing '-' letters
	and not otherwise.

	if, after the last letter, the floating string != ""
	then you can remove that word from the potentialWords set.
	*/

	/*
	
	do you need to backtrack?
	fill it in with letters and then check when word complete
	if word complete and isWord then insert into the set
	keep backtracking?

	if '-' are equal to the number of floating letters
	only try the floating letters.

	*/




}

bool isWord(const std::string& word, const std::set<std::string>& dict)
{	
	return dict.find(word) != dict.end();
	//auto it = dict.find(word);

	//// Check if element was found
	//if (it != dict.end()) {
	//	return true;
	//}
	//else {
	//	return false;
	//}
}
