#include <bits/stdc++.h>
using namespace std;

int main() {
    unordered_set<long long> ex;
    long long n, m;
    cin >> n >> m;
    long long ans = n * n;
    
    for (long long i = 0; i < m; ++i) {
        long long a, b;
        cin >> a >> b;
        --a; --b; // Convert 1-based to 0-based index
        
        long long pos = (a * n + b);
        
        if (!ex.count(pos)) {
            ex.insert(pos);
        } else {
            continue;
        }

        vector<pair<long long, long long>> moves = {
            {2, 1}, {1, 2}, {-1, 2}, {-2, 1}, {-2, -1}, {-1, -2}, {1, -2}, {2, -1}
        };

        for (auto& move : moves) {
            long long nx = a + move.first;
            long long ny = b + move.second;

            if (nx >= 0 && nx < n && ny >= 0 && ny < n) {
                long long npos = (nx * n + ny);
                if (!ex.count(npos)) {
                    ex.insert(npos);
                    --ans;
                }
            }
        }
    }
    
    cout << ans << endl;
    return 0;
}