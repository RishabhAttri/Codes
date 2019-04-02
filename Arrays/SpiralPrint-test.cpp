#include<iostream>
using namespace std;

int main(){
    int arr[3][5]={ {11,12,13,14,15},
                    {21,22,23,24,25},
                    {31,32,33,34,35}};
    int m=3, n=5;

    int rs=0,re=m-1,cs=0,ce=n-1;
    while (rs<=re && cs<=ce){
        //print row rs, move col from cs to ce
        for (int c=cs;c<=ce;c++) cout<<arr[rs][c]<<" ";
        rs++;
        //print last column ce, move row from rs to re
        for (int r=rs;r<=re;r++) cout<<arr[r][ce]<<" ";
        ce--;
        //print last row re, move col from ce to cs
        //if (!(rs<=re && cs<=ce)) break;
        for (int c=ce;rs<=re&&c>=cs;c--) cout<<arr[re][c]<<" ";
        re--;
        //print first col (cs), move rows from re to rs
        for (int r=re;cs<=ce&&r>=rs;r--) cout<<arr[r][cs]<<" ";
        cs++;
    }
}
