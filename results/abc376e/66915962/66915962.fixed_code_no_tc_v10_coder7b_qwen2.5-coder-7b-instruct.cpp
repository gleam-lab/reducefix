#include<bits/stdc++.h>
using namespace std;
using ll = long long;
using VI = vector<int>;
using P = pair<int, int>;
constexpr int INF = 1001001001;
constexpr ll LINF = 1001001001001001001ll;
#define rep(i, n) for (ll i = 0; i < (ll)(n); i++)
#define rep2(i, k, n) for (ll i = k; i < (ll)(n); i++)
#define OUT(x) cout << #x << ":" << x << endl

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    int t;
    cin >> t;
    // vector<vector<int>> v(n, vector<int>(m));

    rep(qi, t){
        int n, k;
        cin >> n >> k;
        vector<ll> a(n), b(n);
        vector<P> p(n);
        rep(i, n) {
            cin >> p[i].first;
            p[i].second = i;
        }
        rep(i, n) cin >> p[i].second;
        sort(p.begin(), p.end());
        rep(i, n){
            auto[aa, bb] = p[i];
            a[i] = aa;
            b[i] = bb;
        }
        ll ans = LINF;
        ll sumB = 0;
        set<int> s;
        rep(i, k){
            s.insert(b[i]);
            sumB += b[i];
        }
        ans = min(ans, a[k-1]*(sumB));
        // OUT(maxA[0]);
        // OUT(sumB[0]);
        // OUT(ans);

        rep2(i, k, n){
            ll smax = *rbegin(s);
            s.erase(smax);
            s.insert(b[i]);
            sumB += b[i] - smax;
            
            ans = min(ans, a[b[i]]*(sumB));
        } 
        cout << ans << '\n';
    }
}