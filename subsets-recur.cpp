#include<bits/stdc++.h>
using namespace std;

vector<vector<int>> res;
vector<int> ar;
vector<int> v = {};


void subsets( int k, int n)
{
    if(k==n) 
    {
        // modify the resultant vector
        res.push_back(v);
    }
    else
    {
        subsets(k+1,n);
        v.push_back(ar[k]);
        subsets(k+1,n);
        // backtrack
        v.pop_back();        
    }
    
}


int main()
{
    int N; 
    cin >> N;
    
    ar.resize(N,0);
    
    for (auto &e: ar) 
        cin >> e;
        
    subsets(0, N);
    
    for(auto e: res) 
    {
        cout << "{ ";
        
        for(auto c: e) 
        {
            cout<< c << " ";
        }
        cout << "}\n";
    }
    return 0;
}
