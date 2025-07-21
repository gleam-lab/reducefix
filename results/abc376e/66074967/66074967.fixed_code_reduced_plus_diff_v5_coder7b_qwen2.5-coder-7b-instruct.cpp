#include<iostream>
#include<vector>
#include<algorithm>
#include<queue>
using namespace std;

const int MAXN = 2e5 + 10;

int main() {
    ios::sync_with_stdio(false); cin.tie(0); cout.tie(0);

    int t;
    cin >> t;
    while (t--) {
        int n, k;
        cin >> n >> k;

        vector<pair<int, int>> a(n), b(n);
        for (int i = 0; i < n; ++i) cin >> a[i].first >> a[i].second;
        for (int i = 0; i < n; ++i) cin >> b[i].first >> b[i].second;

        sort(a.begin(), a.end());
        sort(b.begin(), b.end());

        long long ans = 1LL << 60;
        for (int i = 0; i <= n - k; ++i) {
            long long max_a = a[i + k - 1].first;
            long long sum_b = 0;
            for (int j = i; j < i + k; ++j) sum_b += b[j].first;
            ans = min(ans, max_a * sum_b);
        }

        cout << ans << '\n';
    }

    return 0;
}