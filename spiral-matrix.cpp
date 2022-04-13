// if given an integer 'N', where(1 <= N <= 50) create a spiral matrix of dimension N x N

#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    vector<vector<int>> generateSpiralMatrix(int n) {
        vector<vector<int>> matrix(n, vector<int> (n));
        int value = 1;
        int k = n * n;
        vector<pair<int, int>> dir = {{0, +1} /*right*/, 
                                      {+1, 0}, /*down*/ 
                                      {0, -1},/*left*/ 
                                      {-1, 0} /*up*/
                                     };
        int dirIndex = 0;
        int row = 0;
        int col = 0;
        while(value <= k) {
            if(outsideMatrix(row, col, n) || matrix[row][col] != 0) {
                row -= dir[dirIndex].first;
                col -= dir[dirIndex].second;
                dirIndex = (dirIndex+1) % 4;
            }
            else {
                matrix[row][col] = value;
                value++;
            }
            row += dir[dirIndex].first;
            col += dir[dirIndex].second;
        }
        return matrix;
    }
    
private:
    bool outsideMatrix(int row, int col, int n) {
        return (row < 0 || row >= n) || (col < 0 || col >= n);
    }
};

int main() {
	int n;
	cin >> n;
	
	Solution s1;
	vector<vector<int>> spiralMatrix = s1.generateSpiralMatrix(n);
	
	for(vector<int> &arr: spiralMatrix) {
		for(int x: arr) {
			cout << x << " ";
		}
		cout << endl;
	}
	return 0;
}
