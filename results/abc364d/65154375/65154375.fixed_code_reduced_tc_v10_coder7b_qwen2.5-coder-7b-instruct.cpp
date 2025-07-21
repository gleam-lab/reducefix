#include<bits/stdc++.h>
using namespace std;
typedef long long ll;

int a[200005];

void solve(void) {
    int n, q; cin >> n >> q;
    for(int i = 0; i < n; i++) {
        int x; cin >> x;
        a[x + 100000]++;
    }
    partial_sum(a, a + 200005, a);
    for(int i = 0; i < q; i++) {
        int x, k; cin >> x >> k;
        int pos = lower_bound(a, a + 200005, k) - a;
        cout << abs(pos - x) << endl;
    }
}

int main() {
    ios::sync_with_stdio(0), cin.tie(0), cout.tie(0);
    int t = 1; //cin >> t;
    while(t--) solve();
    return 0;
}