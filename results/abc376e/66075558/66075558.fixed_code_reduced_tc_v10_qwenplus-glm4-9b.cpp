#include <iostream>
#include <vector>
#include <algorithm>
#include <iomanip>
using namespace std;

#define int long long
const int N = 2e5 + 9;

int32_t main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);

    int t;
    cin >> t;
    while (t--) {
        int n, k;
        cin >> n >> k;

        vector<int> a(n + 1), b(n + 1);
        for (int i = 1; i <= n; ++i) {
            cin >> a[i];
        }
        for (int i = 1; i <= n; ++i) {
            cin >> b[i];
        }

        vector<pair<int, int>> index_a(n + 1);
        for (int i = 1; i <= n; ++i) {
            index_a[i] = {a[i], i};
        }

        // Sort by A values
        sort(index_a.begin() + 1, index_a.begin() + n + 1);

        // Process the sorted indices
        long long max_a = index_a[k].first;
        long long sum_b = 0;
        for (int i = 0; i < k; ++i) {
            sum_b += b[index_a[i + 1].second];
        }

        // Calculate the minimum possible value
        long long min_value = max_a * sum_b;
        cout << min_value << '\n';
    }

    return 0;
}