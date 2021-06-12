/*
 *  Matrix exponentiation
*/


#include<bits/stdc++.h>
using namespace std;

#define ll long long
const int mod = 1e9+7;


struct Matrix          
{
    ll a[2][2];
    Matrix (ll x1, ll x2, ll x3, ll x4) 
    {
        a[0][0] = x1;
        a[0][1] = x2;
        a[1][0] = x3;
        a[1][1] = x4;
    }
    Matrix operator * (const Matrix &b)
    {
        Matrix res(0,0,0,0);
        for(int i=0; i<2; i++)
            for(int j=0; j<2; j++)
                for(int k=0; k<2; k++)
                    res.a[i][j] = (res.a[i][j] + a[i][k]*b.a[k][j])%mod;
        return res;
    }
};


int main()
{
    int N;
    cin >> N;
    ll x1, x2, x3, x4;
    cin >> x1 >> x2 >> x3 >> x4;
    Matrix A(1,0,0,1), M(x1,x2,x3,x4);

    while(N)
    {
        // process the matrix
        if(N%2) A = A*M;
        M = M*M;
        N /= 2;
    }
    
    
    for(int i=0; i<2; i++)
    {
        for(int j=0; j<2; j++)
        {
            cout << A.a[i][j] << " ";
        }
        cout << "\n";
    }
    
    return 0;
}

