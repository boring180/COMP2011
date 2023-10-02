#include <iostream>  
using namespace std;	

void noreturn(){
    cout<<"This function is excuted";
    return;
    cout<<"This function should be returned";
}

int main(){

    noreturn();

}