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
    while(t--){
        int n, k;
        cin >> n >> k;
        vector<ll> a(n), b(n);
        vector<P> p(n);
        rep(i, n) cin >> p[i].first;
        rep(i, n) cin >> p[i].second;
        sort(p.begin(), p.end());
        rep(i, n){
            auto[aa, bb] = p[i];
            a[i] = aa;
            b[i] = bb;
        }
        ll ans = LINF;
        ll sumB = accumulate(b.begin(), b.begin()+k, 0LL);
        priority_queue<int> pq(b.begin(), b.begin()+k);
        ans = min(ans, a[k-1]*sumB);
        rep2(i, k, n){
            pq.push(b[i]);
            sumB += b[i];
            sumB -= pq.top();
            pq.pop();
            ans = min(ans, a[i]*sumB);
        } 
        cout << ans << '\n';
    }
}