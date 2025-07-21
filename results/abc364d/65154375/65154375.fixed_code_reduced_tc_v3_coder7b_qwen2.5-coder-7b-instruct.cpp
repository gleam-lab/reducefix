#include<bits/stdc++.h>
using namespace std;

#define rep(i,a,b) for(int i=a;i<b;++i)
#define trav(a,x) for(auto&a:x)

using ll = long long;
using vi = vector<ll>;
using vvi = vector<vi>;

const ll INF = 1e18;
const int MOD = 1e9 + 7;

void solve() {
    ll n, q; cin >> n >> q;
    vi a(n); trav(x, a) cin >> x;
    sort(begin(a), end(a));

    while(q--){
        ll b, k; cin >> b >> k;
        --k; // Adjusting to zero-based index
        auto it = lower_bound(begin(a), end(a), b);
        if(it == begin(a)){
            cout << abs(b - *it) << '\n';
        } else if(it == end(a)){
            cout << abs(b - *(it-1)) << '\n';
        } else {
            ll dist1 = abs(b - *it), dist2 = abs(b - *(it-1));
            if(k < min(dist1, dist2)){
                cout << dist1 << '\n';
            } else if(k >= min(dist1, dist2) && k < dist1 + dist2){
                cout << dist2 << '\n';
            } else {
                cout << abs(b - *(it+1)) << '\n';
            }
        }
    }
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    solve();

    return 0;
}