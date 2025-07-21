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
    cin.tie(nullptr);
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
        priority_queue<ll> pq;
        ll sum_b = 0;
        rep(i, n){
            sum_b += b[i];
            pq.push(b[i]);
            if (pq.size() > k){
                sum_b -= pq.top();
                pq.pop();
            }
            if (pq.size() == k){
                ans = min(ans, a[i] * sum_b);
            }
        }
        cout << ans << '\n';
    }
}