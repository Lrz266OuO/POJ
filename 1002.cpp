/*
 * @Title: 487-3279
 * @Description: 
 *      Businesses like to have memorable telephone numbers. One way to make a telephone number memorable is to have it spell a memorable word or phrase. For example, you can call the University of Waterloo by dialing the memorable TUT-GLOP. Sometimes only part of the number is used to spell a word. When you get back to your hotel tonight you can order a pizza from Gino's by dialing 310-GINO. Another way to make a telephone number memorable is to group the digits in a memorable way. You could order your pizza from Pizza Hut by calling their ``three tens'' number 3-10-10-10.
 *      The standard form of a telephone number is seven decimal digits with a hyphen between the third and fourth digits (e.g. 888-1200). The keypad of a phone supplies the mapping of letters to numbers, as follows:
 *      A, B, and C map to 2
 *      D, E, and F map to 3
 *      G, H, and I map to 4
 *      J, K, and L map to 5
 *      M, N, and O map to 6
 *      P, R, and S map to 7
 *      T, U, and V map to 8
 *      W, X, and Y map to 9
 *      There is no mapping for Q or Z. Hyphens are not dialed, and can be added and removed as necessary. The standard form of TUT-GLOP is 888-4567, the standard form of 310-GINO is 310-4466, and the standard form of 3-10-10-10 is 310-1010.
 *      Two telephone numbers are equivalent if they have the same standard form. (They dial the same number.)
 *      Your company is compiling a directory of telephone numbers from local businesses. As part of the quality control process you want to check that no two (or more) businesses in the directory have the same telephone number.
 * @Input: The input will consist of one case. The first line of the input specifies the number of telephone numbers in the directory (up to 100,000) as a positive integer alone on the line. The remaining lines list the telephone numbers in the directory, with each number alone on a line. Each telephone number consists of a string composed of decimal digits, uppercase letters (excluding Q and Z) and hyphens. Exactly seven of the characters in the string will be digits or letters.
 * @Output: Generate a line of output for each telephone number that appears more than once in any form. The line should give the telephone number in standard form, followed by a space, followed by the number of times the telephone number appears in the directory. Arrange the output lines by telephone number in ascending lexicographical order. If there are no duplicates in the input print the line:
 *      No duplicates.
 */

#include<iostream>
#include<cstdio>
#include<cstring>
#include<algorithm>
#include<iomanip>
#define N 10000000
using namespace std;

int time[N];

int trans(char c) {
    if(c=='A'||c=='B'||c=='C') return 2;
    if(c=='D'||c=='E'||c=='F') return 3;
    if(c=='G'||c=='H'||c=='I') return 4;
    if(c=='J'||c=='K'||c=='L') return 5;
    if(c=='M'||c=='N'||c=='O') return 6;
    if(c=='P'||c=='R'||c=='S') return 7;
    if(c=='T'||c=='U'||c=='V') return 8;
    if(c=='W'||c=='X'||c=='Y') return 9;
    return 0;
}

int main(){
    int n;
    bool flag = false;
    cin>>n;
    string s;
    memset(time, 0, sizeof(time));
    for(int i=0; i<n; i++){
        int tel = 0;
        cin>>s;
        for(int j=0; j<s.length(); j++){
            if(s[j]=='-') continue;
            else if(s[j]<='9') tel = tel*10+(s[j]-'0');
            else if(s[j]<='Z') tel = tel*10+trans(s[j]);
        }
        time[tel]++;
        if(time[tel]>1) flag = true;
    }

    for(int i=0; i<N; i++) {
        if(time[i]>1) cout<<i/10000<<"-"<<i%10000<<" "<<time[i]<<endl;
    }
    if(!flag) cout<<"No duplicates."<<endl;

    return 0;

}


