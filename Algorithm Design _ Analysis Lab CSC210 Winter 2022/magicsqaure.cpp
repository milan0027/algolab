#include <bits/stdc++.h>
using namespace std;

int main()
{

    int n;
    cout<<"Enter a odd no to generate magic square: ";
    cin>>n;

    int a[n][n];


    for(int i=0;i<n;i++)
        for(int j=0;j<n;j++)
            a[i][j]=0;


    int i = n / 2;
    int j = n - 1;


    for (int val = 1; val <= n * n;)
    {
        if (i == -1 && j == n)
        {
            j = n - 2;
            i = 0;
        }


        j%=n;
        i=(i+n)%n;


        if (a[i][j]!=0)
        {
            j-=2;
            i++;
            continue;
        }
        else
            a[i][j] = val++;

        j++;
        i--;
    }

    cout<<"\nThe magic square is--\n\n";

    for (i = 0; i < n; i++)
    {
        for (j = 0; j < n; j++)
            cout << setw(3) << a[i][j] <<" ";

        cout <<"\n";
    }


    return 0;
}
