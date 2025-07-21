#include <bits/stdc++.h>
#define ll long long
using namespace std;

const int N = 2e5 + 5;

ll a[N], b[N];

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);

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

    int i = n, j = n - 1;
    ll required_size = 0;
    int extra_needed = 0;

    while (i >= 1 && j >= 1) {
        if (b[j] >= a[i]) {
            --j;
            --i;
        } else {
            required_size = max(required_size, a[i]);
            ++extra_needed;
            --i;
        }
    }

    if (extra_needed > 1) {
        cout << -1 << '\n';
    } else {
        cout << required_size << '\n';
    }

    return 0;
}