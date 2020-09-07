#include "anagram.h"
#include <iostream>
#include <algorithm>
using namespace std;

bool Anagram::WordPairIsAnagram(const std::string& word1, const std::string& word2) {
    //Fill the correct implementation here
    // Sorting both the strings 
    string sorted1 = word1;
    string sorted2 = word2;
    // Removing white spaces from the strings
    sorted1.erase(remove_if(sorted1.begin(), sorted1.end(), ::isspace), sorted1.end());
    sorted2.erase(remove_if(sorted2.begin(), sorted2.end(), ::isspace), sorted2.end());
    // Getting entire string to one case - lower
    transform(sorted1.begin(), sorted1.end(), sorted1.begin(), ::tolower);
    transform(sorted2.begin(), sorted2.end(), sorted2.begin(), ::tolower);
    sort(sorted1.begin(), sorted1.end());
    sort(sorted2.begin(), sorted2.end());
    
    int len1 = sorted1.length();
    int len2 = sorted2.length();

    // If length of both strings is not same, then they cannot be anagram 
    if (len1 != len2)
        return false;

    // Comparing sorted strings 
    for (int i = 0; i < len1; i++)
        if (sorted1[i] != sorted2[i])
            return false;

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
