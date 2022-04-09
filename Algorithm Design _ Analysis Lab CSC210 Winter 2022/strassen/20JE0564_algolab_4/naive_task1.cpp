#include <bits/stdc++.h>
using namespace std;

void print_matrix(vector< vector<int>> &a, int s){
    for (int i = 0; i < s; i++){
        for (int j = 0; j < s; j++){

            cout << setw(5) << a[i][j]<<" ";
        }
        cout << "\n";
    }
    cout<< "\n";
}
int main()
{

    srand(time(0));
    int n;
    cout<<"2^n is the number of rows and column in matrix(n should be in range 1 to 7)\n";
    cout<<"===========================================================================\n";
    cout<<"Enter n: ";
    cin>>n;

    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    clock_t t1,t2;


    int s=(1<<n);
    vector<vector<int>> mat1(s);
    vector<vector<int>> mat2(s);

    for(int i=0;i<s;i++)
    {

        for(int j=0;j<s;j++)
        {

            mat1[i].push_back(rand()%101);
            mat2[i].push_back(rand()%101);
        }
    }

    t1=clock();

    vector<vector<int>> res(s);

    for(int i=0;i<s;i++)
    {

        for(int j=0;j<s;j++)
        {
            int sum=0;
            for(int k=0;k<s;k++)
            {
                sum+=mat1[i][k]*mat2[k][j];

            }
            res[i].push_back(sum);

        }
    }
    t2=clock();

    cout<<"Random Matrix 1 is--\n";
    print_matrix(mat1,s);
    cout<<"Random Matrix 2 is--\n";
    print_matrix(mat2,s);

    cout<<"Multiplied Matrix is--\n";
    print_matrix(res,s);


    cout<<"Computation time is = "<<((float)(t2-t1)/(float)CLOCKS_PER_SEC)<<" seconds\n";






}
