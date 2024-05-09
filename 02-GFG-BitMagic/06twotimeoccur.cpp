//- XOR the numbers, this now holds the XOR of those two numbers, to seperate them find the rightmost set bit and then do & operation of this bit with everyother bit if its 1 xor with x or with y
/// Rightmost set bit is x&~(x-1)
#include <iostream>
#include <vector>
using namespace std;

void printTwoOdd(int arr[], int size) {
    int xor2 = arr[0];
    int set_bit_no;
    int x = 0, y = 0;

    for (int i = 1; i < size; i++)
        xor2 = xor2 ^ arr[i];
    //xor2 eventually holds the XOR of 2 not same numbers

    set_bit_no = xor2 & ~(xor2 - 1);
    //finds rightmost set bit of xor2

    for (int i = 0; i < size; i++) {
        if (arr[i] & set_bit_no)
            x = x ^ arr[i];
        else
            y = y ^ arr[i];
    }

    cout << "The two ODD elements are " << x << " & " << y;
}

int main() {
    int arr[] = {3, 4, 3, 4, 5, 5, 4, 4, 6, 7, 7, 10};
    int n = sizeof(arr) / sizeof(arr[0]);
    printTwoOdd(arr, n);
    return 0;
}
