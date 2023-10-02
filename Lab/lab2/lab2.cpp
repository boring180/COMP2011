#include <iostream>
using namespace std;

int main() {
    int number1, number2; // Both inputs will be positive integers, but you do not know which is larger
    int small, large; // small should be the smaller of the two numbers, large should be the larger
    int finalScore = 0; // The final score of the game

    // Get the range from the user
    cin >> number1 >> number2;

    /* Please do not change the code above this line */ 

    // Task 1 - Find the small and large bounds of the range
    ///////////////////
    // Your Code Here //
    ///////////////////
    large = (number1 > number2) ? number1 : number2;
    small = (number1 > number2) ? number2 : number1;

    // Task 2 - Find the perfect numbers in the range and update the final score
    ///////////////////
    // Your Code Here //
    ///////////////////
    for(;small <= large; small++)
    {
        int sum = 0;
        for(int i = 1;i < small; i++)
        {
            if (small % i == 0)
                sum += i;
        }
        if(sum == small)
            finalScore += small;
        else
            finalScore -= small;
    }

    /* Please do not change the code below this line */

    cout << finalScore;
    return 0;
}