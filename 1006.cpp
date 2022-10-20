/*
 * @Title: Biorhythms
 * @Description: 
 *      Some people believe that there are three cycles in a person's life that start the day he or she is born. These three cycles are the physical, emotional, and intellectual cycles, and they have periods of lengths 23, 28, and 33 days, respectively. There is one peak in each period of a cycle. At the peak of a cycle, a person performs at his or her best in the corresponding field (physical, emotional or mental). For example, if it is the mental curve, thought processes will be sharper and concentration will be easier.
 *      Since the three cycles have different periods, the peaks of the three cycles generally occur at different times. We would like to determine when a triple peak occurs (the peaks of all three cycles occur in the same day) for any person. For each cycle, you will be given the number of days from the beginning of the current year at which one of its peaks (not necessarily the first) occurs. You will also be given a date expressed as the number of days from the beginning of the current year. You task is to determine the number of days from the given date to the next triple peak. The given date is not counted. For example, if the given date is 10 and the next triple peak occurs on day 12, the answer is 2, not 3. If a triple peak occurs on the given date, you should give the number of days to the next occurrence of a triple peak.
 * @Input:
 *      You will be given a number of cases. The input for each case consists of one line of four integers p, e, i, and d. The values p, e, and i are the number of days from the beginning of the current year at which the physical, emotional, and intellectual cycles peak, respectively. The value d is the given date and may be smaller than any of p, e, or i. All values are non-negative and at most 365, and you may assume that a triple peak will occur within 21252 days of the given date. The end of input is indicated by a line in which p = e = i = d = -1.
 * @Output:
 *      For each test case, print the case number followed by a message indicating the number of days to the next triple peak, in the form:
 *      Case 1: the next triple peak occurs in 1234 days.
 *      Use the plural form ``days'' even if the answer is 1.
 * @Hint: 
 */

#include<iostream>
#include<string.h>
#define N 21620     // 注意特殊数据，例如24,29,34,2
using namespace std;

int time[N];

int main(){
    int count = 1;
    int p, e, i, d;
    while(cin>>p>>e>>i>>d){
        if(p==-1&&e==-1&&i==-1&&d==-1) break;
        memset(time, 0, sizeof(time));
        p = p%23;   // 体力周期23天
        e = e%28;   // 情感周期28天
        i = i%33;   // 智力周期33天
        for(int item=p; item<N; item=item+23){
            time[item]++;
        }
        for(int item=e; item<N; item=item+28){
            time[item]++;
        }
        for(int item=i; item<N; item=item+33){
            time[item]++;
        }
        for(int item=0; item<N; item++){
            if(time[item]==3 && item>d){
                cout<<"Case "<<count<<": the next triple peak occurs in "<<item-d<<" days."<<endl;
                break;
            }
        }
        count++;
    }
    return 0;
}
