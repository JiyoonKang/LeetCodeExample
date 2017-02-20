#include "LongestPalindrome.h"

string LongestPalindrome::longestPalindrome(string s)
{
	if (s.empty()) return "";
	if (s.size() == 1) return s;

	int start = 0, max = 1, left = 0, right = 0;

	int len = s.size();

	for (int i = 0; i<len;)
	{
		left = i;
		right = i;

		while (right < len - 1 && s[right] == s[right + 1])
		{
			++right;
		}

		i = right + 1; // increase index, if right index passed the duplicate char, i will start from the right + 1

		while (left > 0 && right < len - 1 && s[left - 1] == s[right + 1])
		{
			--left;
			++right;
		}

		if (right - left + 1 > max)
		{
			max = right - left + 1;
			start = left;
		}
	}
	return s.substr(start, max);
}
