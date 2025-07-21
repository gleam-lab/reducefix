#include <bits/stdc++.h>
#define ll long long
using namespace std;

const ll N = 2e5 + 5;
ll a[N], b[N];

int main() {
    ll n, cnt = 0, ans = 0, mx = 0;
    cin >> n;
    
    for (ll i = 1; i <= n; ++i) {
        cin >> a[i];
    }
    for (ll i = 1; i < n; ++i) {
        cin >> b[i];
    }

    // Sort the toy sizes and box sizes
    sort(a + 1, a + n + 1);
    sort(b + 1, b + n);

    ll i = 1, j = 1;
    while (i <= n) {
        if (j <= n - 1 && a[i] <= b[j]) {
            i++;
            j++;
        } else {
            if (j == n) {
                cout << -1 << endl;
                return 0;
            }
            j++;
        }
    }

    cout << b[n - 1] << endl;
    return 0;
}