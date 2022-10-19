#include<iostream>
#include<iomanip>
using namespace std;

int main(){
    double money[12];
    double a = 0.0;
    for(int i=0; i<12; i++){
        cin>>money[i];
        a += money[i];
    }
    a = a/12;
    cout<<"$"<<fixed<<showpoint<<setprecision(2)<<a<<endl;
    return 0;
}