//? Question:
//?Given an array where all elements except two occur an even number of times,
//?write a C++ program to find and print these two elements.

//*Difficulty: Medium

#include <iostream>
#include <vector>
using namespace std;

/* Function to find the two odd occurring elements in an array */
void printTwoOdd(int arr[], int size)
{
    int xor2 = arr[0]; // Will hold XOR of two odd occurring elements
    int set_bit_no;    // Will have only single set bit of xor2
    int x = 0, y = 0;

    // Get the XOR of all elements in arr[]
    // The XOR will be the XOR of two odd occurring elements
    for (int i = 1; i < size; i++)
        xor2 = xor2 ^ arr[i];

    // Get one set bit in the xor2.
    // Rightmost set bit is obtained as it is easy to get
    set_bit_no = xor2 & ~(xor2 - 1);

    // Divide elements into two sets:
    // 1) The elements having the corresponding bit as 1
    // 2) The elements having the corresponding bit as 0
    for (int i = 0; i < size; i++)
    {
        if (arr[i] & set_bit_no)
            x = x ^ arr[i]; // XOR of first set holds one odd occurring number x
        else
            y = y ^ arr[i]; // XOR of second set holds the other odd occurring number y
    }

    // Output the two odd elements
    cout << "The two ODD elements are " << x << " & " << y;
}

/* Driver code */
int main()
{
    int arr[] = {3, 4, 3, 4, 5, 5, 4, 4, 6, 7, 7, 10};
    int n = sizeof(arr) / sizeof(arr[0]);
    printTwoOdd(arr, n);
    return 0;
}
