// C++ program to How will you print
// numbers from 1 to 10 without using a loop?
#include <iostream>
using namespace std;

class gfg
{

    // It prints numbers from 1 to n.
public:
    void printNos(unsigned int n) // No tail recursion
    {
        if (n > 0)
        {
            printNos(n - 1);
            cout << n << " ";
        }
        return;
    }
    void printNos(int initial, int last) //optimized tail recursion problem
    {
        if (initial <= last)
        {
            cout << initial << " ";
            printNos(initial + 1, last);
        }
    }
};

// Driver code
int main()
{
    gfg g;
    g.printNos(10);
    return 0;
}