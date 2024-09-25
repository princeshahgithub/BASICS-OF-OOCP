#include<bits/stdc++.h>
//This one includes all the libraries of C++ by which we don't have to write many libraries

using namespace std;

int main() {
    int age;
    cin >> age;
    if(age>=18){
        cout << "You are adult now" << endl;
    }
    else{
        cout << "You are not adult" << endl;
    }
    return 0;
}