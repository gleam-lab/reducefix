#include<bits/stdc++.h>
using namespace std;
using ll = long long;
using VI = vector<int>;
using P = pair<ll, ll>;
constexpr ll INF = 1e18;
constexpr ll LINF = 1e18;
#define rep(i, n) for (ll i = 0; i < (ll)(n); i++)
#define rep2(i, k, n) for (ll i = k; i < (ll)(n); i++)
#define OUT(x) cout << #x << ":" << x << endl

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    int t;
    cin >> t;
    rep(qi, t){
        int n, k;
        cin >> n >> k;
        vector<P> p(n);
        rep(i, n) cin >> p[i].first;
        rep(i, n) cin >> p[i].second;
        sort(p.begin(), p.end());
        vector<ll> a(n), b(n);
        rep(i, n){
            a[i] = p[i].first;
            b[i] = p[i].second;
        }
        ll ans = LINF;
        ll sumB = 0;
        priority_queue<ll, vector<ll>, greater<ll>> pq;
        rep(i, k-1){
            pq.push(b[i]);
            sumB += b[i];
        }
        rep2(i, k-1, n){
            if (pq.size() < k){
                pq.push(b[i]);
                sumB += b[i];
            } else if (b[i] > pq.top()){
                sumB += b[i] - pq.top();
                pq.pop();
                pq.push(b[i]);
            }
            if (pq.size() == k){
                ans = min(ans, a[i] * sumB);
            }
        }
        cout << ans << '\n';
    }
}