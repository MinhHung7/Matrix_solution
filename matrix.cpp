#include<iostream>
#include"funct.h"
#include<vector>
using namespace std;

int main(){
    menu();
    vector<Frac>matrix[hang];
    for(int i=1;i<=hang;++i){
        cout<<"Nhap "<<cot<<" so cho hang "<<i<<": ";
        for(int j=1;j<=cot;++j){
            string *s = new string;
            cin>>*s;
            matrix[i-1].push_back(convertFrac(*s));
            delete s;
        }
    }
    return 0;
}