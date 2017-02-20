#include "PalindromeNum.h"
#include <vector>

using namespace std;

bool PalindromeNum::isPalindrome(int x)
{
    if (x < 0)
        return false;

    vector<int> nums;

    while (x != 0)
    {
        nums.push_back(x % 10);
        x /= 10;
    }

    int size = nums.size();
    int L = 0, R = 0;

    if (size % 2 != 0)
    {
        L = size / 2;
        R = size / 2;
    }
    else
    {
        R = size / 2;
        L = R - 1;
    }

    while (L >= 0 && R < size)
    {
        if (nums[L] != nums[R])
            return false;
        --L;
        ++R;
    }
    return true;
}
