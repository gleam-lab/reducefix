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
    // vector<vector<int>> v(n, vector<int>(m));

    rep(qi, t){
        int n, k;
        cin >> n >> k;
        vector<ll> a(n), b(n);
        vector<P> p(n);
        rep(i, n) {
            cin >> p[i].first;
            a[i] = p[i].first;
        }
        rep(i, n) {
            cin >> p[i].second;
            b[i] = p[i].second;
        }
        sort(p.begin(), p.end());
        
        rep(i, n){
            auto[aa, bb] = p[i];
            a[i] = aa;
            b[i] = bb;
        }

        ll ans = LINF;
        ll sumB = 0;
        priority_queue<ll, vector<ll>, greater<ll>> pq;
        
        rep(i, k){
            pq.push(b[i]);
            sumB += b[i];
        }
        ans = min(ans, a[k-1]*(sumB));
        
        rep2(i, k, n){
            pq.pop();
            pq.push(b[i]);
            sumB += b[i] - pq.top();
            
            ans = min(ans, a[i]*(sumB));
        } 
        
        cout << ans << '\n';
    }
}