#include <iostream>
#include <stdlib.h>
#include <time.h> 
using namespace std;

int main()
{
    srand(time(0));
    int number = rand() % 100 + 1;
    int guess;
    int low = 1;
    int high = 101;
    int Player_Number = 1;

    while (true)
    {
        cout << "Player " << Player_Number << ", please enter your guess:" << endl;
        cin >> guess;
        while ((guess < low || guess > high))
        {
            cout << "Please input a value between" << low << "and" << high << endl;
            cin >> guess;
        }
        if (guess == number)
        {
            cout << "Player " << Player_Number << " wins!" << endl;
            return 0;
        }
        else if (guess > number)
        {
            cout << "Sorry, the number is smaller than " << guess << endl;
            high = guess;
        }
        else
        {
            cout << "The number is bigger" << endl;
            low = guess;
        }
        Player_Number++;
        if (Player_Number == 3)
        {
            Player_Number = 1;
        }
    }
}