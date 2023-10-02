#include <iostream>     /* File: const-ref-arg.cpp */
using namespace std;

void call_by_ref(int& a) { cout << a << endl; }
void call_by_const_ref(const int& a) { cout << a << endl; }

int main() 
{
    int x = 50;
    const int y = 100;
    // Which of the following give(s) compilation error?
    /* passing const literals */
    //call_by_ref(1234);//err
    call_by_const_ref(1234);//1234

    /* passing const objects */
    //call_by_ref(y); 
    call_by_const_ref(y);//1234

    /* passing non-const objects */
    call_by_ref(x);//1234
    call_by_const_ref(x);//1234
    return 0;
}

//