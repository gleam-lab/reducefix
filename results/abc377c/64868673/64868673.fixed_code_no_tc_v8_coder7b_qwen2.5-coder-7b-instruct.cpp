#include <bits/stdc++.h>
using namespace std;

int main() {
    unordered_set<long long> ex;
    long long n, m;
    cin >> n >> m;
    long long ans = n * n - m;
    
    for (long long i = 0; i < m; i++) {
        long long a, b;
        cin >> a >> b;
        long long idx = (a - 1) * n + b - 1;
        
        // Check all possible positions that can capture this piece
        vector<vector<long long>> moves = {{2, 1}, {1, 2}, {-1, 2}, {-2, 1}, {-2, -1}, {-1, -2}, {1, -2}, {2, -1}};
        for (auto& move : moves) {
            long long nx = a + move[0], ny = b + move[1];
            if (nx >= 1 && nx <= n && ny >= 1 && ny <= n) {
                long long nidx = (nx - 1) * n + ny - 1;
                ex.insert(nidx);
            }
        }
    }

    // Subtract the size of the set from the total number of cells
    ans -= ex.size();
    cout << ans << endl;
    return 0;
}