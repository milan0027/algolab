//Milan Mundhra 20JE0564
//.cpp file run in linux
#include <bits/stdc++.h>
using namespace std;
int N;
void print(vector<vector<int>> &a)
{
    cout<<"Arrangement of queens is as follows(q denotes queen)--\n";
    for (int i = 0; i < N; i++) {
        for (int j = 0; j < N; j++)
            cout<<(a[i][j]==1?"q":"0")<<" ";

        cout<<"\n";
    }
}

bool isValid(vector<vector<int>> &a,int row, int col)
{
    int i, j;
    for (i = 0; i < col; i++)
        if (a[row][i])
            return false;

    for (i = row, j = col; i >= 0 && j >= 0; i--, j--)
        if (a[i][j])
            return false;

    for (i = row, j = col; j >= 0 && i < N; i++, j--)
        if (a[i][j])
            return false;

    return true;
}

bool solve(vector<vector<int>> &a, int col)
{
    if (col >= N)
        return true;

    for (int i = 0; i < N; i++) {
        if (isValid(a, i, col)) {
            a[i][col] = 1;
            if (solve(a, col + 1))
                return true;

            a[i][col] = 0;
        }
    }

    return false;
}

int main()
{
   cout<<"Enter N: ";
   cin>>N;

   vector<vector<int>> a( N , vector<int> (N, 0));

    if (!solve(a, 0))
        cout<<"Solution does not exist\n";
    else
        print(a);

    return 0;
}
