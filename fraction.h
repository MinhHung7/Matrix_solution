#pragma once
#include"funct.h"
#include<iostream>
using namespace std;

long long gcd(long long a, long long b){
    long long temp;
    while((a%b)!=0){
        temp = a;
        a=b;
        b = temp%b;
    }
    return b;
}

typedef struct fraction{
    long long tu=0, mau=0;
    void rutgon(){
        long long temp = gcd(this->tu,this->mau);
        this->tu = this->tu/temp;
        this->mau = this->mau/temp;
    }
    void show(){
        if(mau==1){
            cout<<tu;
        }
        else{
            cout<<tu<<"/"<<mau;
        }
    }
}Frac;

Frac add(Frac &a, Frac b){
    long long temp = a.mau;
    a.mau =a.mau* b.mau;
    a.tu = a.tu*b.mau + temp*b.tu;
    a.rutgon();
    return a;
}
Frac add(Frac &a, long long b){
    a.tu = a.mau*b + a.tu;
    a.rutgon();
    return a;
}
Frac multi(Frac &a, Frac b){
    a.tu = a.tu*b.tu;
    a.mau = a.mau*b.mau;
    a.rutgon();
    return a;
}
Frac multi(Frac &a, long long b){
    a.tu = a.tu*b;
    a.rutgon();
    return a;
}