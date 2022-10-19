/*
Financial Management
Input: The input will be twelve lines. Each line will contain the closing balance of his bank account for a particular month. Each number will be positive and displayed to the penny. No dollar sign will be included.
Output: The output will be a single number, the average (mean) of the closing balances for the twelve months. It will be rounded to the nearest penny, preceded immediately by a dollar sign, and followed by the end-of-line. There will be no other spaces or characters in the output.
*/

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