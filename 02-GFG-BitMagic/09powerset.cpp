/*
    ?Title: Print Power Set

    *Approach:
    We use bit manipulation to generate all subsets of a given set.
    For each number from 0 to 2^set_size - 1, we check the set bits and print the corresponding elements.

    -Time Complexity: O(2^N), where N is the size of the set
    -Space Complexity: O(1)
*/

//-Did not really understand the for loops and the logic
#include <bits/stdc++.h>
using namespace std;

void printPowerSet(char *set, int set_size)
{
    unsigned int pow_set_size = pow(2, set_size); // total possible combinations possible
    int counter, j;
    for (counter = 0; counter < pow_set_size; counter++)
    {
        for (j = 0; j < set_size; j++)
        {
            if (counter & (1 << j))
                cout << set[j];
        }
        cout << endl;
    }
}

int main()
{
    char set[] = {'a', 'b', 'c'};
    printPowerSet(set, 3);
    return 0;
}