#include<iostream>
using namespace std;
/**int main()
{///APPROACH 1
     int n; cin>>n;
     int i=1;
    int n1=n/2+1;


  while(i<=n1)
  {

      int j=1;
        while(j<=n1-i)
        {
            cout<<"  ";
            j++;
        }
        while(j>n1-i&&j<=2+i)
        {
             cout<<"* ";
              j++;
        }
        cout<<endl;
        i++;

  }

  int k=1;
   while(i>n1&&i<=n)
   {
      k=n1-i+3;
       int j=1;
       while(j<=n1-k)
        {
            cout<<"  ";
            j++;
        }
        while(j>n1-k&&j<=2+k)
        {
             cout<<"* ";
              j++;
        }
        cout<<endl;

       i++;
   }

}**/


///APPROACH 2
int main()
{

    int n;
    cin>>n;
    int n1=n/2+1;
    int cnt=0;
    int i=1;
    while(true)
    {
        ///space
        int j=1;
        while(j<=n1-i)
        {
            cout<<" ";
            j++;
        }
        ///star
        int k=1;
        while(true)
        {
            cout<<"*";
            if(k==2*i-1)
            {break;}
            k++;
        }
        cout<<endl;

        cnt++;
        if(cnt>=n1)
            i--;
        if(cnt<n1)
            i++;
        if(cnt==n)
            break;

    }
}
