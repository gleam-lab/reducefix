#include<bits/stdc++.h>
using namespace std;
typedef long long ll;

vector<ll> a, b, c;

void solve() {
    int n, q; cin >> n >> q;
    a.resize(n); b.resize(q);
    for(int i = 0; i < n; i++) cin >> a[i];
    for(int i = 0; i < q; i++) cin >> b[i] >> c[i];

    sort(a.begin(), a.end());
    
    for(int i = 0; i < q; i++){
        auto it = lower_bound(a.begin(), a.end(), b[i]);
        int idx = it - a.begin();
        if(idx == 0) cout << abs(b[i] - a[idx]) << endl;
        else if(idx == n) cout << abs(b[i] - a[idx - 1]) << endl;
        else{
            int dist1 = abs(b[i] - a[idx]);
            int dist2 = abs(b[i] - a[idx - 1]);
            if(dist1 <= dist2) cout << dist1 << endl;
            else cout << dist2 << endl;
        }
    }
}

int main(){
    ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
    int t = 1; //cin >> t;
    while (t--) solve();
    return 0;
}