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
    cout<<"+------------------------------+\n";
}
long long posOne(Frac **matrix, long long i, long long j){
    bool check=false;
    for(long long h=i;h<hang;++h){
        if(matrix[h][j].tu!=0) check=true;
        if(equal(matrix[h][j], add(matrix[i][j], 1)) || equal(matrix[h][j],add(matrix[i][j],-1))){
            return h;
        }
    }
    if(check==false){
        return -2;   // Ko chuan hoa duoc
    }
    else return -1;  // Co the chuan hoa bang cach chia chinh no
}

void resolute(Frac **& matrix){
    long long i=0;
    for(long long j=0;j<cot;++j){
        long long h = posOne(matrix, i, j);
        if(h==-1){
            Frac temp = matrix[i][j];
            for(long long k=0;k<cot;++k){
                matrix[i][k] = divide(matrix[i][k],temp);
            }
        }
        else if(h==-2){
            continue;
        }
        else{
            if(equal(matrix[h][j], add(matrix[i][j], -1))){
                for(long long k=0;k<cot;++k){
                    matrix[h][k].tu*=-1;
                    matrix[i][k] = add(matrix[i][k], matrix[h][k]);
                }
            }
            else if(equal(matrix[h][j], add(matrix[i][j], 1))){
                for(long long k=0;k<cot;++k){
                    matrix[i][k].tu*=-1;
                    matrix[i][k] = add(matrix[h][k], matrix[i][k]);
                }
            }
        }
        for(long long k = 0;k<hang;++k){
            if(k!=i){
                Frac thamSo = multi(matrix[k][j], -1);
                for(int m=0;m<cot;++m){
                    matrix[k][m] = add(matrix[k][m], multi(thamSo, matrix[i][m]));
                }
            }
        }
        ++i;
        show(matrix);
    }
}