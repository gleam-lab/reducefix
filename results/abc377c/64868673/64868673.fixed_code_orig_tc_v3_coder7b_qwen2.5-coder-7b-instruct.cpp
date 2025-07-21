#include <bits/stdc++.h>
using namespace std;

const int MOD = 1e9 + 7;

int main() {
    long long n, m;
    cin >> n >> m;
    
    // Directions for the knight moves
    vector<int> dx = {2, 2, 1, 1, -1, -1, -2, -2};
    vector<int> dy = {1, -1, 2, -2, 2, -2, 1, -1};

    // Set to store positions of all pieces
    set<pair<long long, long long>> pieces;
    for(long long i = 0; i < m; ++i) {
        long long a, b;
        cin >> a >> b;
        pieces.insert({a, b});
    }

    // Count valid empty cells
    long long count = 0;
    for(long long i = 1; i <= n; ++i) {
        for(long long j = 1; j <= n; ++j) {
            bool valid = true;
            for(int d = 0; d < 8; ++d) {
                long long ni = i + dx[d], nj = j + dy[d];
                if(ni >= 1 && ni <= n && nj >= 1 && nj <= n) {
                    if(pieces.count({ni, nj})) {
                        valid = false;
                        break;
                    }
                }
            }
            if(valid) {
                count = (count + 1) % MOD;
            }
        }
    }

    cout << count << endl;
    return 0;
}