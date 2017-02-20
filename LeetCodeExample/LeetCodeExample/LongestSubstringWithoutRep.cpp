#include "LongestSubstringWithoutRep.h"
#include <vector>

using namespace std;

int LongestSubWithoutRep::lengthOfLongestSubstring(string s)
{
	auto it = s.begin();

	string sub;

	int max = 0;

	while (it != s.end())
	{
		// check current char is in the current sub string
		check(sub, *it);

		if (max < sub.size())
			max = sub.size();

		++it;
	}

    return max;
}

void LongestSubWithoutRep::check(std::string& str, char chr)
{
	auto it = str.begin();
	
	while (it != str.end())
	{
		if (*it == chr)
		{
			break;
		}
		++it;
	}

	if(it == str.end())
		str.push_back(chr);
	else
	{
		std::string newstr;
		
		++it;

		while (it != str.end())
		{
			newstr.push_back(*it);
			++it;
		}

		newstr.push_back(chr);

		str = newstr;
	}
}
