#include <bits/stdc++.h>
using namespace std;

#define rep(i, n) for (int i = 0; i < (n); ++i)
#define rep1(i, n) for (int i = 1; i <= (n); ++i)
#define ALL(v) v.begin(), v.end()
#define chmin(x, y) x = min(x, y)
#define chmax(x, y) x = max(x, y)

typedef long long ll;
typedef pair<int, int> P;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int t;
    cin >> t;
    while (t--) {
        int n, k;
        cin >> n >> k;
        vector<int> a(n), b(n);
        rep(i, n) cin >> a[i];
        rep(i, n) cin >> b[i];

        sort(ALL(a));
        sort(ALL(b));

        int max_a = a[n - 1];
        ll sum_b = accumulate(ALL(b), ll(0)) - b[n - 1];
        ll ans = max_a * sum_b;

        rep(i, n - k) {
            sum_b += b[i] - b[i + k];
            chmin(ans, a[n - k - 1 - i] * sum_b);
        }

        cout << ans << "\n";
    }

    return 0;
}