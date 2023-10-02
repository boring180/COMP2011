#include <iostream>
using namespace std;

int main()
{
    int row_number;
    bool fat;
    bool upside_down;
    bool hollow;
    int number_of_asterisk;
    int max_row = 10;
    int max_iterations = 10;
    cout << "Please input your desired row number(Enter 0 to start the ultimate RAT): " << endl;
    cin >> row_number;
    if (row_number == 0)
    {
        for (int current_row = 1; current_row <= max_row; current_row++) //From the top row to the bottom row
        {
            for (int current_iteration = 1; current_iteration <= max_iterations; current_iteration++) // For the left iteration to the right iteration
            {
                for (int i = 1; i <= current_row; i++)//The Asterisk
                {
                    cout << "*";
                }
                for (int i = 1; i <= (max_row - current_row); i++)//The blank
                {
                    cout << " ";
                }
            }
            cout << "\n";
        }
    }
    return 0;

while (row_number <= 1)
{
    cout << "Please input a number greater than 1: " << endl;
    cin >> row_number;
}
cout << "Do you want a fat RAT?(1 for yes, 0 for no)" << endl;
cin >> fat;
cout << "Do you want a upside_down RAT?(1 for yes, 0 for no)" << endl;
cin >> upside_down;
cout << "Do you want a hollow RAT?(1 for yes, 0 for no)" << endl;
cin >> hollow;
for (int current_row = 1; current_row <= row_number; current_row++)
{
    int temp = current_row;
    if (upside_down)
        current_row = row_number - current_row + 1;
    number_of_asterisk = current_row;
    if (fat)
        number_of_asterisk = (number_of_asterisk * 2) - 1;
    if (hollow)
    {
        cout << "*";
        for (int j = 2; j < number_of_asterisk; j++)
        {
            if (current_row == row_number)
                cout << "*";
            else
                cout << " ";
        }
        if (number_of_asterisk > 1)
            cout << "*";
    }
    else
        for (int j = 0; j < number_of_asterisk; j++)
        {
            cout << "*";
        }
    cout << "\n";
    current_row = temp;
}
return 0;
}