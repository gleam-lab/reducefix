#include <bits/stdc++.h>
#define INF 0x3f3f3f3f3f3f3f3f
using namespace std;
typedef long long ll;
const int MAXN = 2e5 + 10;

ll a[MAXN], f[MAXN][2];
int cnt[MAXN][2];

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    ll n;
    cin >> n;
    for (ll i = 1; i <= n; ++i) {
        cin >> a[i];
    }

    cnt[0][0] = 0; // even count
    cnt[0][1] = 1; // odd count

    for (ll i = 1; i <= n; ++i) {
        // Case not taking i-th as odd group end
        if (f[i-1][0] > f[i-1][1]) {
            f[i][0] = f[i-1][0];
            cnt[i][0] = cnt[i-1][0];
        } else {
            f[i][0] = f[i-1][1];
            cnt[i][0] = cnt[i-1][1];
        }

        // Case taking i-th as odd group end
        ll odd_contribution, even_contribution;
        if ((cnt[i-1][0] % 2) == 0) {
            odd_contribution = a[i] * 2;
        } else {
            odd_contribution = a[i];
        }
        if ((cnt[i-1][1] % 2) == 0) {
            even_contribution = a[i] * 2;
        } else {
            even_contribution = a[i];
        }

        ll val0 = f[i-1][0] + a[i];
        ll val1 = f[i-1][1] + (a[i] * 2 - a[i]); // this simplifies to a[i]

        if (val0 > val1) {
            f[i][1] = val0;
            cnt[i][1] = cnt[i-1][0] + 1;
        } else {
            f[i][1] = val1;
            cnt[i][1] = cnt[i-1][1] + 1;
        }
    }

    cout << max(f[n][0], f[n][1]) << endl;

    return 0;
}