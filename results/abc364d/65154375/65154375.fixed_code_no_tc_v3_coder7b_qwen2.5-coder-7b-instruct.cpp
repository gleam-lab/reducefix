#include<bits/stdc++.h>
using namespace std;
typedef long long ll;

const int N = 100010;
vector<ll> a(N);

void solve(void) {
    int n, q; cin >> n >> q;
    for(int i = 0; i < n; i++) {
        ll x; cin >> x;
        a[x]++;
    }
    partial_sum(a.begin(), a.end(), a.begin());
    for(int i = 0; i < q; i++) {
        ll x, k; cin >> x >> k;
        ll pos = lower_bound(a.begin(), a.end(), k) - a.begin();
        cout << abs(pos - x) << '\n';
    }
}

int main() {
    ios::sync_with_stdio(0), cin.tie(0), cout.tie(0);
    solve();
    return 0;
}