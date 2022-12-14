/*
 * @Title: The Triangle
 * @Description: 
 *      7
 *      3   8
 *      8   1   0
 *      2   7   4   4
 *      4   5   2   6   5
 *      (Figure 1)
 *      Figure 1 shows a number triangle. Write a program that calculates the highest sum of numbers passed on a route that starts at the top and ends somewhere on the base. Each step can go either diagonally down to the left or diagonally down to the right.
 * @Input: 
 *      Your program is to read from standard input. The first line contains one integer N: the number of rows in the triangle. The following N lines describe the data of the triangle. The number of rows in the triangle is > 1 but <= 100. The numbers in the triangle, all integers, are between 0 and 99.
 * @Output: 
 *      Your program is to write to standard output. The highest sum is written as an integer.
 * @Hint: 
 */

#include<iostream>
using namespace std;
int tri[105][105];

int main(){
    int ans = 0;
    int n;
    cin>>n;
    for(int i=0; i<n; i++){
        for(int j=0; j<i+1; j++){
            cin>>tri[i][j];
        }
    }
    for(int i=n-1; i>0; i--){
        for(int j=0; j<n-1; j++){
            tri[i-1][j] += max(tri[i][j], tri[i][j+1]);
        }
    }

    cout<<tri[0][0]<<endl;
    return 0;
}