#include <string>
#include <vector>

namespace Anagram
{
    bool WordPairIsAnagram(const std::string& word1, const std::string& word2);

    std::vector<std::string> SelectAnagrams(
        const std::string& word,
        const std::vector<std::string>& candidates);
    bool compareSortedStrings(std::string& word1, std::string& word2);
} // namespace Anagram
