#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define pb push_back
#define all(x) x.begin(), x.end()

class Solution {
public:
    int solve(int n, int m, vector<pair<int, int>>& positions) {
        unordered_set<ll> taken;
        for (auto& pos : positions) {
            taken.insert((ll)pos.first * n + pos.second);
        }

        ll count = 0;
        for (int i = 1; i <= n; ++i) {
            for (int j = 1; j <= n; ++j) {
                if (taken.count((ll)i * n + j)) continue;

                bool valid = true;
                vector<pair<int, int>> moves = {{2, 1}, {1, 2}, {-1, 2}, {-2, 1}, {-2, -1}, {-1, -2}, {1, -2}, {2, -1}};
                for (auto& move : moves) {
                    int ni = i + move.first;
                    int nj = j + move.second;
                    if (ni >= 1 && ni <= n && nj >= 1 && nj <= n && !taken.count((ll)ni * n + nj)) {
                        valid = false;
                        break;
                    }
                }
                if (valid) count++;
            }
        }
        return count;
    }
};

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    
    int n, m;
    cin >> n >> m;
    vector<pair<int, int>> positions(m);
    for (int i = 0; i < m; ++i) {
        cin >> positions[i].first >> positions[i].second;
    }

    Solution sol;
    cout << sol.solve(n, m, positions) << endl;
    
    return 0;
}