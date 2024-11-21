#include <iostream>
#include <string>
#include "set.h"

int lengthOfLongestSubstring(const std::string& s) {
    int n = s.length();
    Myset uniqueChars;
    int maxLength = 0;
    int start = 0;

    for (int end = 0; end < n; ++end) {
        char currentChar = s[end];

        
        while (uniqueChars.Get(currentChar)) {
            
            uniqueChars.Remove(s[start]);
            ++start;
        }


        uniqueChars.Add(currentChar);


        maxLength = std::max(maxLength, end - start + 1);
    }

    return maxLength;
}

int main() {
    std::string s1 = "abcbcde";
    std::cout << "Input: " << s1 << std::endl;
    std::cout << "Output: " << lengthOfLongestSubstring(s1) << std::endl;

    std::string s2 = "bbbbb";
    std::cout << "Input: " << s2 << std::endl;
    std::cout << "Output: " << lengthOfLongestSubstring(s2) << std::endl;

    return 0;
}