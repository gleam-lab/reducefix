#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;

#define int long long
const int inf = 1e18;

int n, m, t, ans, k;
vector<pair<int, int>> a, b;

signed main() {
    ios_base::sync_with_stdio(false); cin.tie(0); cout.tie(0);

    cin >> t;
    while (t--) {
        a.clear();
        b.clear();

        cin >> n >> k;
        for (int i = 0; i < n; i++) {
            int x; cin >> x;
            a.push_back({x, i});
        }
        for (int i = 0; i < n; i++) {
            int x; cin >> x;
            b.push_back({x, i});
        }

        sort(a.begin(), a.end());
        sort(b.begin(), b.end());

        int max_a = 0;
        int sum_b = 0;
        for (int i = 0; i < k; i++) {
            max_a = max(max_a, a[n - 1 - i].first);
            sum_b += b[i].first;
        }

        ans = max_a * sum_b;
        cout << ans << '\n';
    }

    return 0;
}