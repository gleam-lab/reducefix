#include <iostream>
#include <set>
#include <vector>

using namespace std;

int main() {
    long long n, m, a, b;
    cin >> n >> m;
    set<pair<int, int>> occupied;
    vector<pair<int, int>> pieces(M);
    
    for (int i = 0; i < m; ++i) {
        cin >> a >> b;
        a--; b--; // Convert to 0-indexed
        pieces[i] = {a, b};
        occupied.insert({a, b});
        
        // Check and mark the pieces that can be captured by the current piece
        for (int x = a - 2; x <= a + 2; ++x) {
            for (int y = b - 2; y <= b + 2; ++y) {
                if (x >= 0 && x < n && y >= 0 && y < n) {
                    occupied.insert({x, y});
                }
            }
        }
    }
    
    // Count the number of empty squares
    long long empty_squares = 0;
    for (long long i = 0; i < n; ++i) {
        for (long long j = 0; j < n; ++j) {
            if (!occupied.count({i, j})) {
                empty_squares++;
            }
        }
    }
    
    cout << empty_squares << endl;
    return 0;
}