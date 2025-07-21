#include<bits/stdc++.h>
using namespace std;
typedef long long ll;

const int N = 1e5 + 5;
ll a[N], b[N];

void solve() {
    int n, q; cin >> n >> q;
    vector<pair<ll, int>> dists(n);
    for(int i = 0; i < n; i++) cin >> a[i];
    sort(a, a + n);
    for(int i = 0; i < q; i++) {
        cin >> b[i] >> dists[i].second;
        dists[i].first = abs(b[i]);
    }
    sort(dists.begin(), dists.end());
    int idx = 0;
    for(int i = 0; i < q; i++) {
        while(idx < n && a[idx] < dists[i].first) idx++;
        if(idx == n) cout << "inf\n";
        else cout << a[idx] - dists[i].first << '\n';
    }
}

int main() {
    ios_base::sync_with_stdio(false); cin.tie(NULL);
    solve();
    return 0;
}