#include <iostream>
#include <cstring>
using namespace std;
#define m 5
#define n 4

int RatinMaze_Count(char Board[m][n],int rRow, int rCol){
    static int cnt=0;
    if (rRow==m-1 && rCol==n-1){
        cnt++;
        return cnt;
    }
    ///lets move right
    if (rCol+1<n && Board[rRow][rCol+1]!='h'){
        RatinMaze_Count(Board,rRow, rCol+1);
    }
    ///let move down
    if (rRow+1<m && Board[rRow+1][rCol]!='h'){
        RatinMaze_Count(Board,rRow+1,rCol);
    }
    return cnt;
}

int main(){
    char Board[m][n]={ {'n','n','n','n'},
                       {'n','h','n','h'},
                       {'n','h','n','n'},
                       {'n','h','h','n'},
                       {'n','n','n','n'}};
    int cnt=RatinMaze_Count(Board,0,0);
    cout<<cnt;


}
