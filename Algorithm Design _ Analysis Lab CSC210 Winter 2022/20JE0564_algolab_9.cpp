#include <bits/stdc++.h>
using namespace std;
//Milan Mundhra
//20JE0564
//.cpp file run in linux
#define vi vector<int>
#define vvi vector<vector<int>>
#define vvvi vector<vector<vector<int>>>
vvvi mat;
void print(vvi &vv)
{
    for(auto v:vv)
    {
        for(auto i:v)
            cout<<i<<" ";
        cout<<"\n";
    }

}

vvi multiply (vvi &mat1, vvi &mat2){

    int m=mat1.size();
    int n=mat1[0].size();
    int p=mat2[0].size();

    cout<<"Multiplying the following matrices now:\n";
    cout<<"First Matrix:\n";
    print(mat1);

    cout<<"Second matrix:\n";
    print(mat2);

    vvi C(m,vi(p));
    for(int i=0;i<m;i++){
        for(int j=0;j<p;j++){
                C[i][j]=0;
          for(int k=0;k<n;k++){
            C[i][j]=C[i][j]+mat1[i][k]*mat2[k][j];
          }
        }
    }

    cout<<"Total operations here = "<<m*n*p<<"\n";
    cout<<"The multiplication result is:\n";
    print(C);
    return C;
}

vvi random_mat(int n,int m)
{
    srand(time(0));
    vector<vector<int>> adj(n,vector<int> (m));
    for(int i=0;i<n;i++)
    {
        for(int j=0;j<m;j++)
        {
            adj[i][j]=rand()%11;
        }
    }

    return adj;

}

vvi printParenthesis(int i, int j, int n, int* bracket,int& name,string &s)
{
    if (i==j)
    {
        s+='M';
        s+=to_string(++name);
        return mat[name-1];
    }

    s+='(';

    vvi val1 = printParenthesis(i, *((bracket + i * n) + j), n,
                     bracket, name,s);

    vvi val2 = printParenthesis(*((bracket + i * n) + j) + 1, j, n,
                     bracket, name,s);

    vvi res=multiply(val1,val2);
    s+=')';
    return res;
}

void matrixChainOrder(int p[], int n)
{

    int m[n][n];
    int bracket[n][n];
    for (int i = 1; i < n; i++)
        m[i][i] = 0;

    for (int L = 2; L < n; L++)
    {
        for (int i = 1; i < n - L + 1; i++)
        {
            int j = i + L - 1;
            m[i][j] = INT_MAX;
            for (int k = i; k <= j - 1; k++)
            {
                int q = m[i][k] + m[k + 1][j]
                        + p[i - 1] * p[k] * p[j];
                if (q < m[i][j])
                {
                    m[i][j] = q;

                    bracket[i][j] = k;
                }
            }
        }
    }

    int name = 0;
    string s="";
    printParenthesis(1, n - 1, n, (int*)bracket, name,s);
    cout << "Optimal order is : "<<s<<"\n";
    cout << "Total no of operations is : " << m[1][n - 1];
}

int main()
{
    srand(time(0));
    cout<<"Enter the number of matrices: ";
    int m;
    cin>>m;
    int arr[m+1];
    int prev=0;
    for(int i=1;i<=m;i++)
    {
        int N,M;
        cout<<"Matrix M"<<i<<":\n"<<"Enter dimension N x M: ";
        cin>>N>>M;
        if(i>1&&N!=prev)
        {

            cout<<"You have entered invalid matrix dimensions\n";
            i--;
            cout<<"Enter again\n";
            continue;
        }
        arr[i-1]=N;
        mat.push_back(random_mat(N,M));
        if(i==m)
        arr[i]=M;
        prev=M;

    }
    for(int i=1;i<=m;i++)
    {
        cout<<"Random Matrix M"<<i<<" is:\n";
        print(mat[i-1]);
    }
    matrixChainOrder(arr, m+1);
    return 0;
}
