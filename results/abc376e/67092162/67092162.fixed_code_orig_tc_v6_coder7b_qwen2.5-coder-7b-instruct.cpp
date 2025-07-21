#include <bits/stdc++.h>
using namespace std;

const int maxN = 2e5 + 5;
int t, n, k, a[maxN], b[maxN];

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    cin >> t;
    while (t--) {
        cin >> n >> k;
        vector<pair<int, int>> ab(n);
        for (int i = 0; i < n; ++i) {
            cin >> a[i];
            ab[i] = {a[i], i};
        }
        for (int i = 0; i < n; ++i) {
            cin >> b[i];
        }

        // Sort A in descending order
        sort(ab.begin(), ab.end(), [&](const pair<int, int>& x, const pair<int, int>& y) {
            return x.first > y.first || (x.first == y.first && x.second < y.second);
        });

        // Sort B in ascending order based on original indices
        sort(b, b + n);

        long long ans = LLONG_MAX;
        int sum = 0;
        int j = 0;
        
        for (int i = 0; i < n && j < k; ++i) {
            sum += b[j++];
            ans = min(ans, static_cast<long long>(ab[i].first) * sum);
        }

        cout << ans << "\n";
    }
    return 0;
}