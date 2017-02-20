#include "MedianofTwoSortedArray.h"

double MedianofArray::findMedianSortedArrays(vector<int>& nums1, vector<int>& nums2)
{
	//Find the median of the two sorted arrays. 
	//The overall run time complexity should be O(log (m+n)).
	int size1 = nums1.size();
	int size2 = nums2.size();
	
	if (size1 == 0 && size2 == 0)
		return 0;
	else if (size1 == 0)
		return FindMedian(nums2);
	else if (size2 == 0)
		return FindMedian(nums1);

	if (nums1[size1 - 1] <= nums2[0])
	{
		return FindMedian(nums1, nums2);
	}
	else if (nums2[size2 - 1] <= nums1[0])
	{
		return FindMedian(nums2, nums1);
	}
	else
	{
		vector<int> result = MergeArray(nums1, nums2);
		return FindMedian(result);
		
		//
		//Optimize 
		//

	}
}

double MedianofArray::FindMedian(vector<int> first, vector<int> second)
{
	int m   = first.size();
	int n   = second.size();
	int sum = m + n;

	if (sum % 2 == 0)
	{
		int    secondindex = sum / 2.f;
		int    firstindex  = secondindex - 1;
		double num_1 = 0.0, num_2 = 0.0;

		if (firstindex <= m - 1)
			num_1 = first[firstindex];
		else
			num_1 = second[firstindex - m];

		if (secondindex <= m - 1)
			num_2 = first[secondindex];
		else
			num_2 = second[secondindex - m];

		return (num_1 + num_2) / 2.0;
	}
	else
	{
		int index = sum / 2.f;

		if (index <= m - 1)
			return first[index];
		else
			return second[index - m];
	}
}

double MedianofArray::FindMedian(vector<int> first)
{
	int sum = first.size();
	int index = sum / 2.f;

	if (sum % 2 == 0)
		return (first[index] + first[index - 1]) / 2.0;
	else
		return first[index];
}

vector<int> MedianofArray::MergeArray(vector<int> nums1, vector<int> nums2)
{
	vector<int> result = nums1;

	for (int i = 0; i < nums2.size(); ++i)
		result.push_back(nums2[i]);

	MergeSort(result, 0, result.size() - 1);

	return result;
}

void MedianofArray::Merge(vector<int>& arr, int low, int high, int mid)
{
	int i, j, k;
	int n1 = mid - low + 1;
	int n2 = high - mid;

	vector<int> L;
	L.resize(n1);
	vector<int> R;
	R.resize(n2);

	for (i = 0; i < n1; i++)
		L[i] = arr[low + i];
	for (j = 0; j < n2; j++)
		R[j] = arr[mid + 1 + j];

	i = 0;
	j = 0;
	k = low;

	while (i < n1 && j < n2)
	{
		if (L[i] <= R[j])
		{
			arr[k] = L[i];
			i++;
		}
		else
		{
			arr[k] = R[j];
			j++;
		}
		k++;
	}

	while (i < n1)
	{
		arr[k] = L[i];
		i++;
		k++;
	}

	while (j < n2)
	{
		arr[k] = R[j];
		j++;
		k++;
	}
}

void MedianofArray::MergeSort(vector<int>& arr, int low, int high)
{
	if (low < high)
	{
		int m = (low + (high - 1)) / 2;
		MergeSort(arr, low, m);
		MergeSort(arr, m + 1, high);

		Merge(arr, low, high, m);
	}
}
