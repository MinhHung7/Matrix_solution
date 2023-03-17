#include<iostream>
#include"interfaceFunct.h"
#include"fraction.h"
using namespace std;

int main(){
    menu();
    Frac **matrix = new Frac*[hang];
    for(int i=0;i<hang;++i){
        *(matrix+i) = new Frac[cot];
        cout<<"Nhap "<<cot<<" so cho hang "<<i<<": ";
        for(int j=0;j<cot;++j){
            string *s = new string;
            cin>>*s;
            *(*(matrix+i)+j) = convertFrac(*s);
            delete s;
        }
    }
    resolute(matrix);
    for(int i=0;i<hang;++i){
        delete[]matrix[i];
    }
    delete[] matrix;
    return 0;
}
