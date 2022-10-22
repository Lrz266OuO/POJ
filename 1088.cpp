/*
 * @Title: 滑雪
 * @Description: 
 *      Michael喜欢滑雪百这并不奇怪， 因为滑雪的确很刺激。可是为了获得速度，滑的区域必须向下倾斜，而且当你滑到坡底，你不得不再次走上坡或者等待升降机来载你。Michael想知道载一个区域中最长底滑坡。区域由一个二维数组给出。数组的每个数字代表点的高度。下面是一个例子
 *      1  2  3  4  5
 *      16 17 18 19 6
 *      15 24 25 20 7
 *      14 23 22 21 8
 *      13 12 11 10 9
 *      一个人可以从某个点滑向上下左右相邻四个点之一，当且仅当高度减小。在上面的例子中，一条可滑行的滑坡为24-17-16-1。当然25-24-23-...-3-2-1更长。事实上，这是最长的一条。
 * @Input: 
 *      输入的第一行表示区域的行数R和列数C(1 <= R,C <= 100)。下面是R行，每行有C个整数，代表高度h，0<=h<=10000。
 * @Output: 
 *      输出最长区域的长度。
 * @Hint: 
 */

#include<iostream>
using namespace std;

int to[4][2] = {{1,0},{-1,0},{0,1},{0,-1}};
int n, m;
int high[105][105];
int maxlen[105][105];

int check(int x, int y){
    if(x>=1 && y>=1 && x<=n && y<=m) return 1;
    else return 0;
}

int dfs(int x, int y){
    if(maxlen[x][y] != 0) return maxlen[x][y];
    maxlen[x][y] = 1;
    for(int i=0; i<4; i++){
        int x1 = x + to[i][0];
        int y1 = y + to[i][1];
        if(check(x1, y1) && high[x1][y1]<high[x][y]){
            maxlen[x][y] = max(maxlen[x][y], 1+dfs(x1, y1));
        }
    }
    return maxlen[x][y];
}

int main(){
    cin>>n>>m;
    int ans = 1;
    for(int i=1; i<=n; i++){
        for(int j=1; j<=m; j++){
            cin>>high[i][j];
            maxlen[i][j] = 0;
        }
    }
    for(int i=1; i<=n; i++){
        for(int j=1; j<=m; j++){
            ans = max(ans, dfs(i, j));
        }
    }
    cout<<ans<<endl;
    return 0;
}