#include <bits/stdc++.h>
using namespace std;
#define int long long
#define PII pair<int, int>
#define fi first
#define se second
#define arr array<int, 3>

const int N = 2e5 + 10, INF = 0x3f3f3f3f, mod = 1e9 + 7;

int a[N], b[N];
PII sa[N];

signed main() {
    ios::sync_with_stdio(0);
    cin.tie(0), cout.tie(0);

    int t;
    cin >> t;

    while (t--) {
        int n, k;
        cin >> n >> k;

        for (int i = 1; i <= n; i++) {
            cin >> a[i];
        }

        for (int i = 1; i <= n; i++) {
            cin >> b[i];
        }

        // Sort A and B in descending order
        sort(a + 1, a + 1 + n, greater<int>());
        sort(b + 1, b + 1 + n, greater<int>());

        int res = 0;
        for (int i = 0; i < k; i++) {
            res += a[i + 1] * b[i + 1];
        }

        cout << res << endl;
    }

    return 0;
}