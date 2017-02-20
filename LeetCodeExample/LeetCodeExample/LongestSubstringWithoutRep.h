#pragma once
#include <string>
using namespace std;

class LongestSubWithoutRep {
public:
    int lengthOfLongestSubstring(string s);

	void check(std::string& str, char chr);
};