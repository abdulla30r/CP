#include <bits/stdc++.h>
using namespace std;
void printBinary(int num){
    for(int i=10;i>=0;--i){
        cout << ((num>>i) & 1);
    }
    cout <<endl;
}

void lowerCase(char ch){
    //cout << char(int(ch) | (1<<5));
    cout << char(ch | ' ')<<endl;
}

void upperCase(char ch){
   //cout << char(ch & ~(1<<5));
    cout << char(ch & '_') <<endl;
}

int main(){
    int a = 11;
    //printBinary(int('.'));

    //cout << __builtin_popcount(a);

    lowerCase('A');
    upperCase('a');
    return 0;
}