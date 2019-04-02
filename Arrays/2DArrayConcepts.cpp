#include<iostream>
using namespace std;

int main(){
    int arr[3][4]={{1,2,3,4},{5,6,7,8}};
    cout<<arr[2][3]<<endl;

    int arr1[4][5]={ {11,12,13,14,15},
                    {21,22,23,24,25},
                    {31,32,33,34,35},
                    {41,42,43,44,45}};

    cout<<"1:"<<arr << endl;
    cout <<"2:"<< arr+1 << endl;
    cout <<"3:"<< *(arr+1) << endl;
    cout <<"4:"<<arr[0] << endl;
    cout <<"5:" <<*(arr[0]) << endl;
    cout <<"6:"<< &arr[0][0] << endl;
    cout <<"7:"<< arr[0] + 1 << endl;
    cout <<"8:"<< (&arr[0][0]) + 1 << endl;
    cout <<"9:"<< arr+1 << endl;
    cout <<"10:"<< &arr[1][0] << endl;




}
