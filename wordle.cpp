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


// Definition of primary wordle function
std::set<std::string> wordle(
    const std::string& in,
    const std::string& floating,
    const std::set<std::string>& dict)
{
    // Add your code here


	/*
	build it up 1 letter at a time
	storing and updating a set of 
	"possibles"	

	// dict is passed as reference because it's too big to make a copy of each time
	// could you keep popping out of dict? So it's smaller each time you pass it.
	// But then you would lose the dict from posterity.

	// where to store the set?

	*/


}

// Define any helper functions here
