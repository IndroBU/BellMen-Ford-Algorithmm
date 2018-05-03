
///God Help Me;
#include<bits/stdc++.h>
using namespace std;
typedef long long int lli;
#define inf 1e5 + 3
lli A[100];
lli B[100];
lli W[100][100];
lli n,e;
int D[100];
int StrCount=0;
string StringHome[100];
int Search_Index(string s)
{
    for(int I=1; I<=StrCount; I++)
    {
        if(StringHome[I]==s)
        {
            return I;
        }
    }
    StrCount = StrCount +1;
    StringHome[StrCount] = s;
    return StrCount;
}
void BellManFord()
{
    for(int l=1; l<=n-1; l++)
    {
        for(int i=1; i<=e; i++)
        {
            int U=A[i];
            int V=B[i];
            if(D[V]>D[U]+W[U][V]) D[V]=D[U]+W[U][V];
        }
    }

}

int main()
{
    lli x,y,d; lli i,j;
    cout<<"Enter Node and Edge : ";
    cin>>n>>e;
    for(i=1; i<=n; i++)
    {
        for(j=1; j<=n; j++)
        {
            if(i==j) W[i][j]=0;
            else W[i][j]=inf;
        }
    }
    string s1,s2;
    for(i=1; i<=e; i++)
    {
       cin>>s1>>s2>>d;
       x=Search_Index(s1);
       y=Search_Index(s2);
       A[i]=x;
       B[i]=y;
       W[x][y]=d;
    }
    string  src,Dst;
    cout<<"Enter Source Node : ";
    cin>>src;
    D[Search_Index(src)]=0;
    for(int i=1; i<=n; i++)
    {
        if(i!=Search_Index(src))
            D[i]=inf;
        //else D[i]=0;
    }
    BellManFord();
     cout<<"Enter Destination Node : ";
     cin>>Dst;
    cout<<D[Search_Index(Dst)]<<endl;
    cout<<"Check How Many NegaTive Circle :"<<endl;
        for(int i=1; i<=e; i++)
        {
            int U=A[i];
            int V=B[i];
            if(D[V]>D[U]+W[U][V])
            {
                cout<<"Here is a Negative Cycle ;p"<<endl;
            }
        }
    return 0;
}

