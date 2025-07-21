#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int n, k;
vector<pair<int, int>> a, b;

int main() {
    int t;
    cin >> t;
    while (t--) {
        cin >> n >> k;
        a.clear();
        b.clear();
        a.reserve(n);
        b.reserve(n);

        for (int i = 0; i < n; i++) {
            int x;
            cin >> x;
            a.emplace_back(x, i);
        }

        for (int i = 0; i < n; i++) {
            int x;
            cin >> x;
            b.emplace_back(x, i);
        }

        sort(a.begin(), a.end(), greater<pair<int, int>>());
        vector<int> prefix_sum(n + 1, 0);

        for (int i = n - 1; i >= 0; i--) {
            prefix_sum[i] = prefix_sum[i + 1] + b[i].first;
        }

        long long min_value = LLONG_MAX;
        for (int i = k; i <= n; i++) {
            for (int j = 0; j <= n - i; j++) {
                long long sum_b = prefix_sum[j + i - 1] - prefix_sum[j];
                min_value = min(min_value, (long long)a[j].first * sum_b);
            }
        }

        cout << min_value << endl;
    }
    return 0;
}