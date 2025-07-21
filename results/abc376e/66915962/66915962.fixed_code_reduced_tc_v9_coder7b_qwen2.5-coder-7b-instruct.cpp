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
    int t;
    cin >> t;
    // vector<vector<int>> v(n, vector<int>(m));

    rep(qi, t){
        int n, k;
        cin >> n >> k;
        vector<ll> a(n), b(n);
        vector<P> p(n);
        rep(i, n) {
            cin >> a[i];
            p[i].first = a[i];
            p[i].second = i;
        }
        rep(i, n) cin >> b[i];
        
        sort(p.begin(), p.end());
        sort(b.begin(), b.end());

        ll ans = LINF;
        ll sumB = 0;
        priority_queue<ll, vector<ll>, greater<ll>> pq;

        rep(i, k){
            pq.push(b[p[i].second]);
            sumB += b[p[i].second];
        }

        ans = min(ans, a[k-1] * sumB);

        rep2(i, k, n){
            sumB -= pq.top();
            pq.pop();
            pq.push(b[p[i].second]);
            sumB += b[p[i].second];
            ans = min(ans, a[i] * sumB);
        } 

        cout << ans << '\n';
    }
}