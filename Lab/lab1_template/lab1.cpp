#include <iostream>
using namespace std;
int main()
{
    int width, height; // Define 2 variables that will hold the width and height respectively

    cout << "Please input the width of the rectangle: "; 
    cin >> width; 
    cout << "Please input the height of the rectangle: "; 
    cin >> height; 

    // TODO: complete your program here
    int Perimeter;
    if(width > 0 && height > 0){
        Perimeter = 2 * (width + height );
        cout << "The perimeter of the rectangle is " << Perimeter << endl ;
    }
    else{
        cout<<"Error: the width and height must be positive!" << "\n";
    }
    
    
    return 0;
}