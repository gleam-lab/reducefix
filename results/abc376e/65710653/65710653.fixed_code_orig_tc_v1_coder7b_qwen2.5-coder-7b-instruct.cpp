#include <bits/stdc++.h>
using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int t;
    cin >> t;
    while (t--) {
        int n, k;
        cin >> n >> k;
        
        vector<pair<int, int>> ab(n);
        for (int i = 0; i < n; ++i) {
            cin >> ab[i].first;
        }
        for (int i = 0; i < n; ++i) {
            cin >> ab[i].second;
        }

        // Sort pairs by the sum of A and B in descending order
        sort(ab.begin(), ab.end(), [](const auto &p1, const auto &p2) {
            return p1.first + p2.first > p1.second + p2.second;
        });

        int max_A = 0;
        long long sum_B = 0;
        for (int i = 0; i < k; ++i) {
            max_A = max(max_A, ab[i].first);
            sum_B += ab[i].second;
        }

        cout << max_A * sum_B << '\n';
    }

    return 0;
}