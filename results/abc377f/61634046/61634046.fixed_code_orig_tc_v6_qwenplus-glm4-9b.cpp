#include <iostream>
#include <vector>
#include <unordered_set>

using namespace std;

const int MAX_N = 1000;

int n, m;
vector<pair<int, int>> pieces(MAX_N);
unordered_set<int> capturedRows, capturedCols, capturedDiags1, capturedDiags2;

int main() {
    cin >> n >> m;
    
    for (int i = 0; i < m; ++i) {
        int x, y;
        cin >> x >> y;
        pieces[i] = {x, y};
        
        // Capturing in row
        capturedRows.insert(x);
        
        // Capturing in column
        capturedCols.insert(y);
        
        // Capturing on diagonal i+j
        capturedDiags1.insert(x + y);
        
        // Capturing on diagonal i-j
        capturedDiags2.insert(x - y);
    }
    
    // Calculate total number of empty squares
    long long totalSquares = n * n;
    
    // Subtract captured squares
    // Captured in any row
    for (int row : capturedRows) {
        totalSquares -= n;
    }
    
    // Captured in any column
    for (int col : capturedCols) {
        totalSquares -= n;
    }
    
    // Captured on any diagonal i+j
    for (int diag : capturedDiags1) {
        totalSquares -= min(n, diag);  // Diagonal length cannot exceed n
    }
    
    // Captured on any diagonal i-j
    for (int diag : capturedDiags2) {
        totalSquares -= min(n, diag);  // Diagonal length cannot exceed n
    }
    
    cout << totalSquares << endl;
    return 0;
}