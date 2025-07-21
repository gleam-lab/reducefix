#include <iostream>
#include <vector>
#include <algorithm>
#include <climits>

using namespace std;

int main() {
    int t;
    cin >> t;
    while (t--) {
        long long n, k;
        cin >> n >> k;
        vector<pair<long long, long long>> a(n);
        vector<long long> b(n);
        for (int i = 0; i < n; ++i) {
            cin >> a[i].first;
            cin >> b[i];
        }

        // Sort the pairs (a[i], b[i] - a[i]) to find the minimum value of max(a_i) * sum(b_i - a_i)
        sort(a.begin(), a.end(), [](const pair<long long, long long>& p1, const pair<long long, long long>& p2) {
            return p1.first * (p2.second - p1.first) < p2.first * (p2.second - p1.first);
        });

        long long current_sum_b = 0;
        long long answer = LLONG_MAX;
        vector<pair<long long, long long>> b_minus_a(n);
        for (int i = 0; i < n; ++i) {
            b_minus_a[i] = {b[i] - a[i].first, a[i].first};
            current_sum_b += b[i] - a[i].first;
        }

        // Find the index where we should start from to maintain the sum of b_i's equal to or greater than k * max(a_i)
        auto pos = lower_bound(b_minus_a.begin(), b_minus_a.end(), make_pair(0, k * inf));
        long long sum_b_CURRENT = 0;
        for (int i = pos - b_minus_a.begin(); i < n; ++i) {
            sum_b_CURRENT += b_minus_a[i].first;
            long long val = sum_b_CURRENT * b_minus_a[i].second;
            answer = min(answer, val);
        }

        cout << answer << endl;
    }
    return 0;
}