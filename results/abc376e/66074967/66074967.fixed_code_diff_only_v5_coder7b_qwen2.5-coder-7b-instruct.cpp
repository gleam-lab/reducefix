#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;

#define ll long long
const int N = 2e5 + 9, inf = 1000000009;

int n, m, t, ans, k;
ll s;
pair<ll, ll> a[N], b[N];

signed main() {
    ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
    cin >> t;
    while (t--) {
        cin >> n >> k;
        for (int i = 1; i <= n; i++) {
            cin >> a[i].first;
            a[i].second = i;
        }
        for (int i = 1; i <= n; i++) {
            cin >> b[i].first;
            b[i].second = i;
        }
        sort(a + 1, a + n + 1);
        sort(b + 1, b + n + 1);

        ll max_a = -1, sum_b = 0;
        for (int i = 0; i < k; i++) {
            max_a = max(max_a, a[n - i].first);
            sum_b += b[n - i].first;
        }

        ans = max_a * sum_b;

        for (int i = n - k - 1; i >= 0; i--) {
            max_a = max(max_a, a[i].first);
            sum_b -= b[n - i].first;
            sum_b += b[n - k - 1 - i].first;
            ans = min(ans, max_a * sum_b);
        }

        cout << ans << endl;
    }
    return 0;
}