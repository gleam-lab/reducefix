#include <bits/stdc++.h>
using namespace std;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    
    int n, m;
    cin >> n >> m;
    
    set<pair<long long, long long>> occupied;
    for (int i = 0; i < m; ++i) {
        long long a, b;
        cin >> a >> b;
        occupied.insert({a, b});
    }

    long long count = 0;
    for (long long i = 1; i <= n; ++i) {
        for (long long j = 1; j <= n; ++j) {
            bool can_place = true;
            vector<pair<int, int>> moves = {{2, 1}, {1, 2}, {-1, 2}, {-2, 1}, {-2, -1}, {-1, -2}, {1, -2}, {2, -1}};
            for (auto& move : moves) {
                long long ni = i + move.first;
                long long nj = j + move.second;
                if (ni >= 1 && ni <= n && nj >= 1 && nj <= n && occupied.find({ni, nj}) != occupied.end()) {
                    can_place = false;
                    break;
                }
            }
            if (can_place) {
                ++count;
            }
        }
    }

    cout << n * n - count << endl;
    return 0;
}