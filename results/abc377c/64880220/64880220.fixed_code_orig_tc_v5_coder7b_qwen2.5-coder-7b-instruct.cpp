#include <bits/stdc++.h>
using namespace std;

int main() {
    long long n, m;
    cin >> n >> m;
    
    // Store positions of all pieces
    set<pair<long long, long long>> pieces;
    for(long long i = 0; i < m; ++i) {
        long long a, b;
        cin >> a >> b;
        pieces.insert({a, b});
    }

    // Directions for capturing moves
    vector<pair<int, int>> directions = {
        {2, 1}, {1, 2}, {-1, 2}, {-2, 1},
        {-2, -1}, {-1, -2}, {1, -2}, {2, -1}
    };

    // Count valid empty cells
    long long count = 0;
    for(long long i = 1; i <= n; ++i) {
        for(long long j = 1; j <= n; ++j) {
            bool isValid = true;
            for(auto& dir : directions) {
                long long ni = i + dir.first;
                long long nj = j + dir.second;
                if(ni >= 1 && ni <= n && nj >= 1 && nj <= n) {
                    if(pieces.find({ni, nj}) != pieces.end()) {
                        isValid = false;
                        break;
                    }
                }
            }
            if(isValid) {
                count++;
            }
        }
    }

    cout << count << endl;
    return 0;
}