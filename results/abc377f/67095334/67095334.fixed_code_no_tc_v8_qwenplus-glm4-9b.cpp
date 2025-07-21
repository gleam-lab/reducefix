#include<bits/stdc++.h>
using namespace std;

#define MOD 1000000007

int main() {
    long long n, m;
    cin >> n >> m;
    vector<pair<int, int>> pieces(m);
    for (int i = 0; i < m; i++) {
        cin >> pieces[i].first >> pieces[i].second;
    }

    long long emptyCells = n * n;
    set<pair<int, int>> occupied;

    for (int i = 0; i < m; i++) {
        int x = pieces[i].first;
        int y = pieces[i].second;
        occupied.insert({x, y});
        emptyCells--;

        // Remove the cells in the same row and column
        emptyCells -= (n - 1);
        
        // Remove the cells in the diagonals i+j and i-j
        for (int i = 2; i <= n; i++) {
            if (x + y == i || x - y == i) {
                occupied.insert({i - x, i - y});
            }
        }
        emptyCells -= (n - 1);
    }

    // Remove the first cell (1,1) from empty cells if it is occupied
    if (occupied.count({1, 1})) {
        emptyCells--;
    }
    
    cout << emptyCells << endl;
    return 0;
}