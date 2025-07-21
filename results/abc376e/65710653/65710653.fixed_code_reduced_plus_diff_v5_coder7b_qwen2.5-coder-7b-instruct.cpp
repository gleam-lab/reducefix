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

        sort(ab.begin(), ab.end());

        long long sum_b = 0;
        for (int i = 0; i < k; ++i) {
            sum_b += ab[i].second;
        }

        long long min_value = INT_MAX;
        for (int i = 0; i <= n - k; ++i) {
            min_value = min(min_value, static_cast<long long>(ab[i + k - 1].first) * sum_b);
            if (i > 0) {
                sum_b -= ab[i - 1].second;
                sum_b += ab[i + k - 1].second;
            }
        }

        cout << min_value << "\n";
    }

    return 0;
}