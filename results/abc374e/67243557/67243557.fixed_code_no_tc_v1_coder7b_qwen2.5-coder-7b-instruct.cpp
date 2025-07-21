#include <bits/stdc++.h>
using namespace std;
#define rep(i,n) for(long long i=0;i<n;i++)
using ll = long long;
using Graph = vector<vector<int>>;

ll f(int a, int b, int p, int q, int x) {
    ll ans = 0;
    ll pa = max((ll)0, x / a);
    ll pb = max((ll)0, x / b);
    ans = min(pa * p, pb * q);
    return ans;
}

int main() {
    int n, x;
    cin >> n >> x;
    vector<int> a(n), b(n), p(n), q(n);
    rep(i, n) cin >> a[i] >> p[i] >> b[i] >> q[i];

    ll left = 0, right = 1e9;
    while (left < right) {
        ll mid = (left + right + 1) / 2;
        ll total_cost = 0;
        bool possible = true;
        for (int i = 0; i < n; ++i) {
            total_cost += f(a[i], b[i], p[i], q[i], mid);
            if (total_cost > x) {
                possible = false;
                break;
            }
        }
        if (possible) {
            left = mid;
        } else {
            right = mid - 1;
        }
    }

    cout << left << endl;
    return 0;
}