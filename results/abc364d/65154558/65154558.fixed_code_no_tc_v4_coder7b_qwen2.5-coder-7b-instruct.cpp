#include<bits/stdc++.h>
using namespace std;
typedef long long ll;

vector<ll> a, b;
vector<int> k;

bool comp(ll x, ll y) {
    return abs(x) < abs(y);
}

void solve() {
    int n, q; cin >> n >> q;
    a.resize(n); b.resize(q); k.resize(q);

    for(int i = 0; i < n; i++) cin >> a[i];
    for(int i = 0; i < q; i++) {
        cin >> b[i] >> k[i];
        k[i]--;
    }

    sort(a.begin(), a.end());
    
    for(int i = 0; i < q; i++) {
        vector<ll> dists;
        for(int j = 0; j < n; j++) {
            dists.push_back(abs(b[i] - a[j]));
        }
        sort(dists.begin(), dists.end());
        cout << dists[k[i]] << endl;
    }
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    int t = 1; //cin >> t;
    while(t--) solve();

    return 0;
}