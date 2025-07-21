#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

const int MAX_N = 2e5 + 5;

int main() {
    vector<pair<int, int>> ab;
    cin >> t;
    while (t--) {
        int n, k;
        cin >> n >> k;
        ab.resize(n);
        for (int i = 0; i < n; ++i) {
            cin >> ab[i].first;
            ab[i].second = i;
        }

        sort(ab.begin(), ab.end(), [](const pair<int, int>& a, const pair<int, int>& b) {
            return a.first < b.first;
        });

        long long ans = LLONG_MAX;
        long long sum_b = 0;
        long long max_a = LLONG_MIN;
        for (int i = 0; i < n; ++i) {
            sum_b += ab[i].second;
            max_a = max(max_a, ab[i].first);
            if (i >= k - 1) {
                ans = min(ans, (sum_b + ab[i].second) * max_a);
            }
        }

        cout << ans << endl;
    }
    return 0;
}