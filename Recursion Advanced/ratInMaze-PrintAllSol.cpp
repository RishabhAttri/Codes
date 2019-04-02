#include <iostream>
#include <cstring>
using namespace std;
#define m 5
#define n 4

void PrintSol(char Board[m][n]){
    for (int i=0;i<m;i++){
        for (int j=0;j<n;j++){
            cout<<Board[i][j]<<" ";
        }
        cout<<endl;
    }
    cout<<endl;
}

int RatinMaze_Count(char Board[m][n],int rRow, int rCol){
    static int cnt=0;
    Board[rRow][rCol]='Y';
    if (rRow==m-1 && rCol==n-1){
        cnt++;
        PrintSol(Board);
        Board[rRow][rCol]='n';
        return cnt;
    }
    ///lets move right
    if (rCol+1<n && Board[rRow][rCol+1]!='x'){
        RatinMaze_Count(Board,rRow, rCol+1);
    }
    ///let move down
    if (rRow+1<m && Board[rRow+1][rCol]!='x'){
        RatinMaze_Count(Board,rRow+1,rCol);
    }
    Board[rRow][rCol]='n';
    return cnt;
}

int main(){
    char Board[m][n]={ {'n','n','n','n'},
                       {'n','x','n','x'},
                       {'n','x','n','n'},
                       {'n','n','x','n'},
                       {'n','n','n','n'}};
    int cnt=RatinMaze_Count(Board,0,0);
    cout<<cnt;
    PrintSol(Board);


}
