#include "anagram.h"
#include <iostream>
#include <algorithm>
using namespace std;

void Anagram::WordPreprocessing(string& word)
{
    // Removing white spaces from the strings
    word.erase(remove_if(word.begin(), word.end(), ::isspace), word.end());
    // Removing punctuations
    word.erase(remove_if(word.begin(), word.end(), ::ispunct), word.end());
    // Getting entire string to one case - lower
    transform(word.begin(), word.end(), word.begin(), ::tolower);
    // Sorting each word alphabetically
    sort(word.begin(), word.end());

}

bool Anagram::WordPairIsAnagram(const std::string& word1, const std::string& word2) {
    //Fill the correct implementation here
    // Sorting both the strings 
    string sorted1 = word1;
    string sorted2 = word2;
    
    // pre-processing each word
    WordPreprocessing(sorted1);
    WordPreprocessing(sorted2);

    int len1 = sorted1.length();
    int len2 = sorted2.length();

    // If length of both strings is not same, then they cannot be anagram 
    if (len1 != len2)
        return false;

    // Comparing sorted strings 
    //Anagram::compareSortedStrings(sorted1, sorted2);
    if (sorted1 == sorted2)
        return true;

}

std::vector<std::string> Anagram::SelectAnagrams(
        const std::string& word,
        const std::vector<std::string>& candidates) {
    //Fill the correct implementation here
    vector<string> matchinganagrams;
    for (int i = 0; i < candidates.size(); i++)
    {
        if (Anagram::WordPairIsAnagram(word, candidates[i]))
            matchinganagrams.push_back(candidates[i]);
    }
    return matchinganagrams;
}
