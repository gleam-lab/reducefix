#include <bits/stdc++.h>
#define ll long long
using namespace std;

const int N = 2e5 + 5;

ll a[N], b[N];

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    
    int n;
    cin >> n;
    for (int i = 1; i <= n; ++i) {
        cin >> a[i];
    }
    for (int i = 1; i < n; ++i) {
        cin >> b[i];
    }

    sort(a + 1, a + n + 1);
    sort(b + 1, b + n);

    // Try to match toys with boxes greedily
    int l = n, r = n - 1;
    ll need = 0;
    while (l >= 1 && r >= 1) {
        if (b[r] >= a[l]) {
            --r;
            --l;
        } else {
            // We need an extra box of at least size a[l]
            need = max(need, a[l]);
            --l;
        }
    }

    // At most one toy can be left unmatched, requiring the new box
    if (l == 0 && r >= 0) {
        cout << 0 << '\n';
    } else if (l == 1) {
        cout << a[1] << '\n';
    } else {
        cout << -1 << '\n';
    }

    return 0;
}