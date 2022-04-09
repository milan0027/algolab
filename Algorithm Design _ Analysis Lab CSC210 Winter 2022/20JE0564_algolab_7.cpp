//Milan Mundhra
//20JE0564
//.cpp file run in linux
#include <bits/stdc++.h>
using namespace std;

string s,t;
int n,m;
int dp[3002][3002];
int ways(int i,int j)
{
    if(i>=n||j>=m)
        return dp[i][j]=0;

    if(dp[i][j]!=-2)
        return dp[i][j];

    if(s[i]==t[j])
        return dp[i][j]=1+ways(i+1,j+1);

    dp[i][j]=max(ways(i+1,j),ways(i,j+1));
    return dp[i][j];

}
int32_t main()
{

    cout<<"Enter the first string:\n";
    cin>>s;
    cout<<"Enter the second string:\n";
    cin>>t;
    n=s.length();
    m=t.length();

    for(int i=0;i<=3001;i++)
    {
        for(int j=0;j<=3001;j++)
            dp[i][j]=-2;
    }

    int i=0,j=0;
    int val=ways(0,0);
    string fin="";

    while(i<=n&&j<=m)
    {


        if(dp[i][j]==dp[i+1][j])
        {

            i++;
        }
        else if(dp[i][j]==dp[i][j+1])
        {
            j++;
        }
        else if(dp[i][j]==1+dp[i+1][j+1])
        {
            fin+=s[i];
            i++;
            j++;
        }
        else
            break;


    }

    cout<<"The LCS is:\n"<<fin<<"\n";

}
