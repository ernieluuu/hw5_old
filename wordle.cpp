/*
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
*/


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
bool is_valid_prefix(const std::string& prefix, const std::set<std::string>& dict);
void findWords(const std::string& in, const std::string& floating, const std::set<std::string>& dict, std::set<std::string>& potentialWords, string& curr, int currLoc);
bool isWord(const std::string& word, const std::set<std::string>& dict);

// Definition of primary wordle function
std::set<std::string> wordle(const std::string& in, const std::string& floating, const std::set<std::string>& dict) {
    // Add your code here
    std::set<std::string> potentialWords; // stores potential matches
    
    // if empty string
    if (in.size() == 0) {
        return potentialWords;
    }

    string curr = in;
    findWords(in, floating, dict, potentialWords, curr, 0);

    return potentialWords;
}



// Define any helper functions here
bool is_valid_prefix(const std::string& prefix, const std::set<std::string>& dict) {
    auto it = dict.lower_bound(prefix);
    return it != dict.end() && it->substr(0, prefix.size()) == prefix;
}


/*
 * nvm, scratch all of that you first generate a set / list of possible words and then use the find() method of a set (logn) to check if it is a real word in the english langauge.
 * check if in[currLoc] == '-' or == alphabet_loc
 */
/*this function recursively generates a set of potential letter combinations*/
void findWords(const std::string& in, const std::string& floating, const std::set<std::string>& dict, std::set<std::string>& potentialWords, string& curr, int currLoc)

/*
{
    // where currLoc stands for the current location in 'in'

    // Base case: if all letters are filled, check if it's a valid word
    if (currLoc == in.size()) {
        // Check if the current word is a valid word and all floating letters are used
        if (isWord(curr, dict) && all_of(floating.begin(), floating.end(), [&curr](char c) {
            return curr.find(c) != string::npos;
        })) {
            potentialWords.insert(curr);
        }
        return;
    }

    // If the current location is a fixed letter, move to the next location
    if (in[currLoc] != '-') {
        findWords(in, floating, dict, potentialWords, curr, currLoc + 1);
        return;
    }

    // Try placing floating letters at the current location
    for (char c : floating) {
        if (curr.find(c) == string::npos) {
            curr[currLoc] = c;
            findWords(in, floating, dict, potentialWords, curr, currLoc + 1);
            curr[currLoc] = '-'; // Backtrack
        }
    }

    // Try placing all alphabet letters at the current location
    for (char c = 'a'; c <= 'z'; c++) {
        // Optimization: Skip alphabet letters that are in the floating string
        if (floating.find(c) == string::npos) {
            curr[currLoc] = c;
            // Optimization: Check if the current prefix is valid before recursing
            if (is_valid_prefix(curr.substr(0, currLoc + 1), dict)) {
                findWords(in, floating, dict, potentialWords, curr, currLoc + 1);
            }
            curr[currLoc] = '-'; // Backtrack
        }
    }
}
*/

{
    /* where currLoc stands for the current location in 'in' */

    // Base case: if all letters are filled, check if it's a valid word
    if (currLoc == in.size()) {
        // Check if the current word is a valid word and all floating letters are used
        if (isWord(curr, dict) && all_of(floating.begin(), floating.end(), [&curr, &floating](char c) {
            return std::count(curr.begin(), curr.end(), c) >= std::count(floating.begin(), floating.end(), c);
        })) {
            potentialWords.insert(curr);
        }
        return;
    }

    // If the current location is a fixed letter, move to the next location
    if (in[currLoc] != '-') {
        findWords(in, floating, dict, potentialWords, curr, currLoc + 1);
        return;
    }

    // Try placing floating letters at the current location
    for (char c : floating) {
        curr[currLoc] = c;
        findWords(in, floating, dict, potentialWords, curr, currLoc + 1);
        curr[currLoc] = '-'; // Backtrack
    }

    // Try placing all alphabet letters at the current location
    for (char c = 'a'; c <= 'z'; c++) {
        curr[currLoc] = c;
        // Optimization: Check if the current prefix is valid before recursing
        if (is_valid_prefix(curr.substr(0, currLoc + 1), dict)) {
            findWords(in, floating, dict, potentialWords, curr, currLoc + 1);
        }
        curr[currLoc] = '-'; // Backtrack
    }
}


bool isWord(const std::string& word, const std::set<std::string>& dict) {
    return dict.find(word) != dict.end();
    //auto it = dict.find(word);
    //// Check if element was found
    //if (it != dict.end()) {
    //    return true;
    //}
    //else {
    //    return false;
    //}
}