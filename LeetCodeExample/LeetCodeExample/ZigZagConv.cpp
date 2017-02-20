#include "ZigZagConv.h"
#include <vector>

string ZigZagCon::convert(string s, int numRows)
{
    if (numRows <= 1)
        return s;

    vector<string> list;
    list.resize(numRows);

    int len = (2 * numRows) - 2;

    for (int i = 0; i<s.size(); )
    {
        for (int j = 0; j < len && i < s.size(); ++j)
        {
            if (j <= numRows - 1)
                list[j].push_back(s[i]);
            else
            {
                int index = j - 2 * (j - numRows + 1);
                list[index].push_back(s[i]);
            }
            ++i;
        }
    }

    string result;

    for (int i = 0; i<list.size(); ++i)
        result += list[i];

    return result;
}
