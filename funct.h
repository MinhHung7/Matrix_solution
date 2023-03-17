#include<string>
#include<iostream>
#include<vector>
using namespace std;
long long hang, cot;
long long gcd(long long a, long long b){
    long long temp;
    while(b!=0){
        temp = a;
        a=b;
        b = temp%b;
    }
    return b;
}

typedef struct fraction{
    long long tu=0, mau=0;
    void rutgon(){
        long long temp = gcd(tu, mau);
        tu = tu/temp;
        mau = mau/temp;
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

void show(vector<Frac>matrix[]){
    for(int i=0;i<hang;++i){
        for(int j=0;j<cot;++j){
            matrix[i][j].show();
            cout<<" ";
        }
        cout<<"\n";
    }
}