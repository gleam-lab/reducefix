#include<bits/stdc++.h>
using namespace std;
const int N = 1e6+7;
typedef long long ll;

int main() {
    int n, m;
    ll a[N], b[N], c[N];
    cin >> n;
    for(int i = 0; i < n; i++) {
        cin >> a[i];
    }
    b[0] = 0; // Initialize the first value of b to 0
    for(int i = 1; i <= n; i++) {
        b[i] = b[i - 1] + a[i - 1];
    }
    cin >> m;
    while(m--) {
        int l, r;
        cin >> l >> r;
        ll sum;
        if (r >= a[n]) {
            sum = b[n];
        } else {
            auto l_i = lower_bound(a, a + n, l);
            auto r_j = upper_bound(a, a + n, r);
            sum = (b[upper_bound(a, a + n, r) - a] - b[lower_bound(a, a + n, l) - a]);
        }
        cout << sum << endl;
    }
    return 0;
}