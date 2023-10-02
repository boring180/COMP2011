#include <iostream>
using namespace std;

int main()
{
    cout << boolalpha;
    bool R;
    R = 4 == 5;
    cout << (4 == 5)  << R << endl;
    int x = 5;
    R = x > 0 && x < 10;
    cout <<"x > 0 && x < 10 is" << R << endl;
    R = 5 * 15 +4 == 13 && 12 < 19 || !false == 5 < 24;
    cout <<"5 * 15 +4 == 13 && 12 < 19 || !false == 5 < 24 is" << R << endl;
    R = true && false || true;
    cout <<"true && false || true is" << R << endl;
    x = 5;
    R = 5;
    cout <<"5 is" << R << endl;
    x = 5;
    R = x ++ == 6;
    cout <<"R = x ++ == 6 is" << R << endl;
    R = x = 9;
    cout <<"x = 9 is" << R << endl;
    R = x == 3 == 4;
    cout <<"x == 3 == 4 is" << R << endl;
}