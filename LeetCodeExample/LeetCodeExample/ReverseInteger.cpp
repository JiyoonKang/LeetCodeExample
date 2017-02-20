#include "ReverseInteger.h"
#include <vector>
#include <cmath>

using namespace std;

int ReverseInt::reverse(int x)
{
    bool neg = false;
  
    if (x < 0)
    {
        neg = true;
        x *= -1;
    }

    vector<int> nums;

    while (x != 0)
    {
        nums.push_back(x % 10);
        x = x / 10;
    }

    int result = 0;
    int size = nums.size() - 1;

    for (int i = 0; i < nums.size(); ++i)
    {
        result += nums[i] * pow(10, size);
        --size;
    }

    if (result < 0)
        return 0;

    if (neg)
        result *= -1;

    return result;
}
