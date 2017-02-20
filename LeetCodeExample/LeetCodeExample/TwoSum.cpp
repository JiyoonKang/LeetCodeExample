#include "TwoSum.h"

vector<int> TwoSum::twoSum(vector<int>& nums, int target)
{
    vector<int> result;
    int size = nums.size();

    for (int first = 0; first < size; ++first) {

        for (int second = first + 1; second < size; ++second)
        {
            if (nums[first] + nums[second] == target)
            {
                result.push_back(first);
                result.push_back(second);
                return result;
            }
        }
    }
    return result;
}