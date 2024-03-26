
#include <bits/stdc++.h>
using namespace std;
 
/// APPROACH CAN BE CHANGED AS WRITTEN IN NOTES 
int first(int arr[], int low, int high, int x, int n)
{
    if (high >= low)
    {
        int mid = low + (high - low) / 2;
        /// ONLY EQUAL CASE NEEDS TO BE CHANGED
        if ((mid == 0 || x > arr[mid - 1]) && arr[mid] == x)
            return mid;
        else if (x > arr[mid])
            return first(arr, (mid + 1), high, x, n);
        else
            return first(arr, low, (mid - 1), x, n);
    }
    return -1;
}

int last(int arr[], int low, int high, int x, int n)
{
    if (high >= low)
    {
        int mid = low + (high - low) / 2;
        /// ONLY EQUAL CASE NEEDS TO BE CHANGED
        if ((mid == n - 1 || x < arr[mid + 1]) && arr[mid] == x)
            return mid;
        else if (x < arr[mid])
            return last(arr, low, (mid - 1), x, n);
        else
            return last(arr, (mid + 1), high, x, n);
    }
    return -1;
}

int first(int arr[], int x, int n)
{
	int low = 0, high = n - 1, res = -1;
	while (low <= high) {

		// Normal Binary Search Logic
		int mid = (low + high) / 2;

		if (arr[mid] > x)
			high = mid - 1;
		else if (arr[mid] < x)
			low = mid + 1;

		// If arr[mid] is same as x, we
		// update res and move to the left
		// half.
		else {
			res = mid;
			high = mid - 1;
		}
	}
	return res;
}

///ITERATIVE APPROACH 
//  If x is present in arr[] then returns
// the index of LAST occurrence of x in
// arr[0..n-1], otherwise returns -1 */
// int last(int arr[], int x, int n)
// {
// 	int low = 0, high = n - 1, res = -1;
// 	while (low <= high) {

 		// Normal Binary Search Logic
// 		int mid = (low + high) / 2;

// 		if (arr[mid] > x)
// 			high = mid - 1;
// 		else if (arr[mid] < x)
// 			low = mid + 1;

		// If arr[mid] is same as x, we
		// update res and move to the right
 		// half.
// 		else {
// 			res = mid;
// 			low = mid + 1;
// 		}
// 	}
// 	return res;
// }

int main()
{
    int arr[] = {1, 2, 2, 2, 2, 3, 4, 7, 8, 8};
    int n = sizeof(arr) / sizeof(int);

    int x = 8;
    printf("First Occurrence = %d\t",
           first(arr, 0, n - 1, x, n));
    printf("\nLast Occurrence = %d\n",
           last(arr, 0, n - 1, x, n));
    return 0;
}