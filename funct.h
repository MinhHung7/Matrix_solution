#pragma once
#include<string>
#include<iostream>
#include"fraction.h"
using namespace std;
long long hang, cot;

Frac convertFrac(string s){
    Frac a;
    string tu,mau;
    int posSlash = s.find_first_of('/');
    if(posSlash==string::npos){
        tu = s;
        mau = "1";
    }
    else{
        tu = s.substr(0, posSlash);
        mau = s.substr(posSlash+1);
    }
    try{
        a.tu = stol(tu);
        a.mau = stol(mau);
        return a;
    }
    catch(exception e){
        cout<<"This not a numnber!!";
    }
}

void menu(){
    cout<<"+------------------------------+\n";
    cout<<"| Nhap so hang: ";
    cin>>hang;
    cout<<"| Nhap so cot: ";
    cin>>cot;
    cout<<"+------------------------------+\n";
}

void show(Frac **&matrix){
    for(long long i=0;i<hang;++i){
        for(long long j=0;j<cot;++j){
            matrix[i][j].show();
            cout<<" ";
        }
        cout<<"\n";
    }
}