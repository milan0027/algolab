#include<bits/stdc++.h>
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

void addition(vector<vector<int>> &A, vector<vector<int>> &B, vector<vector<int>> &C, int size){
    int i, j;
    for (i = 0; i < size; i++){
        for (j = 0; j < size; j++){
            C[i][j] = A[i][j] + B[i][j];
        }
    }
}

void subtraction(vector<vector<int>> &A, vector<vector<int>> &B, vector<vector<int>> &C, int size){
    int i, j;
    for (i = 0; i < size; i++){
        for (j = 0; j < size; j++){
            C[i][j] = A[i][j] - B[i][j];
        }
    }
}

void split_STRASSEN(vector<vector<int>> &A, vector<vector<int>> &B, vector<vector<int>> &C, int size){

    if (size == 1){
        C[0][0] = A[0][0] * B[0][0];
        return;
    }
    int new_size = size / 2;
    vector<int> z(new_size);
    vector<vector<int>>
        a11(new_size, z), a12(new_size, z), a21(new_size, z), a22(new_size, z),
        b11(new_size, z), b12(new_size, z), b21(new_size, z), b22(new_size, z),
        c11(new_size, z), c12(new_size, z), c21(new_size, z), c22(new_size, z),
        p1(new_size, z), p2(new_size, z), p3(new_size, z), p4(new_size, z),
        p5(new_size, z), p6(new_size, z), p7(new_size, z),
        aResult(new_size, z), bResult(new_size, z);
    int i, j;

    for (i = 0; i < new_size; i++){
        for (j = 0; j < new_size; j++){
            a11[i][j] = A[i][j];
            a12[i][j] = A[i][j + new_size];
            a21[i][j] = A[i + new_size][j];
            a22[i][j] = A[i + new_size][j + new_size];

            b11[i][j] = B[i][j];
            b12[i][j] = B[i][j + new_size];
            b21[i][j] = B[i + new_size][j];
            b22[i][j] = B[i + new_size][j + new_size];
        }
    }

    addition(a11, a22, aResult, new_size);
    addition(b11, b22, bResult, new_size);
    split_STRASSEN(aResult, bResult, p1, new_size);

    addition(a21, a22, aResult, new_size);
    split_STRASSEN(aResult, b11, p2, new_size);

    subtraction(b12, b22, bResult, new_size);
    split_STRASSEN(a11, bResult, p3, new_size);

    subtraction(b21, b11, bResult, new_size);
    split_STRASSEN(a22, bResult, p4, new_size);

    addition(a11, a12, aResult, new_size);
    split_STRASSEN(aResult, b22, p5, new_size);

    subtraction(a21, a11, aResult, new_size);
    addition(b11, b12, bResult, new_size);

    split_STRASSEN(aResult, bResult, p6, new_size);


    subtraction(a12, a22, aResult, new_size);
    addition(b21, b22, bResult, new_size);

    split_STRASSEN(aResult, bResult, p7, new_size);

    addition(p3, p5, c12, new_size);
    addition(p2, p4, c21, new_size);

    addition(p1, p4, aResult, new_size);
    addition(aResult, p7, bResult, new_size);
    subtraction(bResult, p5, c11, new_size);

    addition(p1, p3, aResult, new_size);
    addition(aResult, p6, bResult, new_size);
    subtraction(bResult, p2, c22, new_size);

    for (i = 0; i < new_size; i++){
        for (j = 0; j < new_size; j++){
            C[i][j] = c11[i][j];
            C[i][j + new_size] = c12[i][j];
            C[i + new_size][j] = c21[i][j];
            C[i + new_size][j + new_size] = c22[i][j];
        }
    }
}

vector<vector<int>> STRASSEN_algorithm(vector<vector<int>> &A, vector<vector<int>> &B, int s){

    vector<int> z(s);
    vector<vector<int>> Aa(s, z), Bb(s, z), Cc(s, z);

    for (int i = 0; i < s; i++){
        for (int j = 0; j < s; j++){
            Aa[i][j] = A[i][j];
        }
    }
    for (int i = 0; i < s; i++){
        for (int j = 0; j < s; j++){
            Bb[i][j] = B[i][j];
        }
    }
    split_STRASSEN(Aa, Bb, Cc, s);

    return Cc;
}

int main(){

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

    vector<vector<int>> A(s);
    for (int i = 0; i < s; i++){

        for (int j = 0; j < s; j++){

            A[i].push_back(rand()%101);
        }

    }

    vector<vector<int>> B(s);
    for (int i = 0; i < s; i++){

        for (int j = 0; j < s; j++){

            B[i].push_back(rand()%101);
        }

    }
    cout<<"Random Matrix 1 is--\n";
    print_matrix(A,s);
    cout<<"Random Matrix 2 is--\n";
    print_matrix(B,s);


    t1=clock();
    vector<vector<int>> C;
    C = STRASSEN_algorithm(A, B, s);
    t2=clock();
    cout<<"Multiplied Matrix is--\n";
    print_matrix(C,s);

    cout<<"Computation time is = "<<((float)(t2-t1)/(float)CLOCKS_PER_SEC)<<" seconds\n";
    return 0;
}
