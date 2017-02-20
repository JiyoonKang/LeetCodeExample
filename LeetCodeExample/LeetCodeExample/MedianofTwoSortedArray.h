#pragma once
#include <vector>

using namespace std;

class MedianofArray {
public:
	double findMedianSortedArrays(vector<int>& nums1, vector<int>& nums2);

	double FindMedian(vector<int> first, vector<int> second);

	double FindMedian(vector<int> first);

	vector<int> MergeArray(vector<int> nums1, vector<int> nums2);

	void MergeSort(vector<int>& arr, int low, int high);

	void Merge(vector<int>& arr, int low, int high, int mid);
};