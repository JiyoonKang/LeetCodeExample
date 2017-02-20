#include "Test.h"

void SudokuTest(void)
{
    std::vector<std::vector<char>> myboard;

    myboard.resize(9);
    for (int r = 0; r < 9; ++r)
    {
        myboard[r].resize(9);
        for (int c = 0; c < 9; ++c)
            myboard[r][c] = '.';
    }

    myboard[0][0] = 5 + 48;
    myboard[0][1] = 3 + 48;
    myboard[0][4] = 7 + 48;
    myboard[1][0] = 6 + 48;
    myboard[1][3] = 1 + 48;
    myboard[1][4] = 9 + 48;
    myboard[1][5] = 5 + 48;
    myboard[2][1] = 9 + 48;
    myboard[2][2] = 8 + 48;
    myboard[2][7] = 6 + 48;
    myboard[3][0] = 8 + 48;
    myboard[3][4] = 6 + 48;
    myboard[3][8] = 3 + 48;
    myboard[4][0] = 4 + 48;
    myboard[4][3] = 8 + 48;
    myboard[4][5] = 3 + 48;
    myboard[4][8] = 1 + 48;
    myboard[5][0] = 7 + 48;
    myboard[5][4] = 2 + 48;
    myboard[5][8] = 6 + 48;
    myboard[6][1] = 6 + 48;
    myboard[6][6] = 2 + 48;
    myboard[6][7] = 8 + 48;
    myboard[7][3] = 4 + 48;
    myboard[7][4] = 1 + 48;
    myboard[7][5] = 9 + 48;
    myboard[7][8] = 5 + 48;
    myboard[8][4] = 8 + 48;
    myboard[8][7] = 7 + 48;
    myboard[8][8] = 9 + 48;

    Solution *sudoku = new Solution();
    sudoku->solveSudoku(myboard);

    //Print
    for (int row = 0; row < maxlength; row++)
    {
        for (int col = 0; col < maxlength; col++)
            printf("%c", myboard[row][col]);
        printf("\n");
    }


}

void AddTwoNumberTest(void)
{
    ListNode *l1 = nullptr;
    ListNode *l2 = nullptr;

    ListNode *test1 = new ListNode(2);
    ListNode *test2 = new ListNode(4);
    ListNode *test3 = new ListNode(3);

    test1->next = test2;
    test2->next = test3;
    l1 = test1;

    ListNode *test4 = new ListNode(5);
    ListNode *test5 = new ListNode(6);
    ListNode *test6 = new ListNode(4);
    ListNode *test7 = new ListNode(9);

    test4->next = test5;
    test5->next = test6;
    test6->next = test7;
    l2 = test4;

    AddTwoNumbers *test = new AddTwoNumbers();

    ListNode* result = test->addTwoNumbers(l1, l2);
    //Print
    while (result != nullptr)
    {
        printf("%d", result->val);
        printf("->");

        result = result->next;
    }
    printf("\n");
}

void LongestSubstringTest(void)
{
	std::string str = "bbbbb";

	LongestSubWithoutRep *longest = new LongestSubWithoutRep();
	
	int max = longest->lengthOfLongestSubstring(str);

	printf("Max : %d", max);

}

void MedianofTwoArrayTest(void)
{
	std::vector<int> num1, num2;
	num1.push_back(1);
	num2.push_back(2);

	num2.push_back(3);
	num2.push_back(4);

	MedianofArray *test = new MedianofArray();
	double median = test->findMedianSortedArrays(num1, num2);
	printf("Median: %f", median);
}

void LongestPalindromeTest(void)
{
	LongestPalindrome *test = new LongestPalindrome();

	std::string result = test->longestPalindrome("aaa");

	int i = 0;

}

void ZigZagTest(void)
{
    ZigZagCon *test = new ZigZagCon();

    string result = test->convert("ABCD", 3);

    int i = 0;//test
}

void RegerseIntTest(void)
{
    ReverseInt *test = new ReverseInt();

    int result = test->reverse(1);
}

void StringToIntTest(void)
{
}

void TwoSumTest(void)
{
    std::vector<int> numbers;
    numbers.push_back(2);
    numbers.push_back(7);
    numbers.push_back(11);
    numbers.push_back(15);

    TwoSum *twosum = new TwoSum();
    std::vector<int> result = twosum->twoSum(numbers, 9);
    //Print
    for (int i = 0; i < 2; i++)
    {
        printf("%d", result[i]);
        printf("\n");
    }

}
