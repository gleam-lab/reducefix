#include <bits/stdc++.h>
#define endl "\n"
using namespace std;
typedef long long ll;

const int N = 2e5 + 5;

int n, q;
int a[N];
int b[N], k[N];

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    cin >> n >> q;
    for (int i = 1; i <= n; ++i) {
        cin >> a[i];
    }
    for (int i = 1; i <= q; ++i) {
        cin >> b[i] >> k[i];
    }

    sort(a + 1, a + n + 1);
    for (int i = 0; i < q; ++i) {
        int x = b[i];
        int idx = upper_bound(a + 1, a + n + 1, x) - (a + 1) - k[i] + 1;
        if (idx == 0) {
            cout << 1e17 << endl;
        } else {
            cout << abs(x - a[idx]) << endl;
        }
    }

    return 0;
}