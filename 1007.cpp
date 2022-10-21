/*
 * @Title: DNA Sorting
 * @Description: 
 *      One measure of "unsortedness" in a sequence is the number of pairs of entries that are out of order with respect to each other. For instance, in the letter sequence "DAABEC", this measure is 5, since D is greater than four letters to its right and E is greater than one letter to its right. This measure is called the number of inversions in the sequence. The sequence "AACEDGG" has only one inversion (E and D)---it is nearly sorted---while the sequence "ZWQM" has 6 inversions (it is as unsorted as can be---exactly the reverse of sorted).
 *      You are responsible for cataloguing a sequence of DNA strings (sequences containing only the four letters A, C, G, and T). However, you want to catalog them, not in alphabetical order, but rather in order of "sortedness", from "most sorted" to "least sorted". All the strings are of the same length.
 * @Input: 
 *      The first line contains two integers: a positive integer n (0 < n <= 50) giving the length of the strings; and a positive integer m (0 < m <= 100) giving the number of strings. These are followed by m lines, each containing a string of length n.
 * @Output: 
 *      Output the list of input strings, arranged from ``most sorted'' to ``least sorted''. Since two strings can be equally sorted, then output them according to the orginal order.
 * @Hint: 
 */


#include<iostream>
#include<string.h>
#include<iomanip>
using namespace std;

struct str_sorted
{
    string str;
    int sorted;
};

int main(){
    int n,m;    // n is the length of the strings, m is the number of strings
    cin>>n>>m;
    struct str_sorted DNA[m];
    for(int i=0; i<m; i++){
        cin>>DNA[i].str;
        DNA[i].sorted = 0;
        for(int j=0; j<n; j++){
            for(int k=j+1; k<n; k++){
                if(DNA[i].str[j]>DNA[i].str[k]) DNA[i].sorted++;
            }
        }
    }
    for(int i=0; i<m; i++){
        for(int j=i+1; j<m; j++){
            if(DNA[i].sorted>DNA[j].sorted){
                string temp1 = DNA[i].str;
                int temp2 = DNA[i].sorted;
                DNA[i].str = DNA[j].str;
                DNA[i].sorted = DNA[j].sorted;
                DNA[j].str = temp1;
                DNA[j].sorted = temp2;
            }
        }
    }
    for(int i=0; i<m; i++){
        cout<<DNA[i].str<<endl;
    }

    return 0;
}
