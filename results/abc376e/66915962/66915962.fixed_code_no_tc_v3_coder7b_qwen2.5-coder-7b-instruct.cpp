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
    ios::sync_with_stdio(false);
    cin.tie(0);
    
    int t;
    cin >> t;
    // vector<vector<int>> v(n, vector<int>(m));

    rep(qi, t){
        int n, k;
        cin >> n >> k;
        vector<ll> a(n), b(n);
        priority_queue<ll, vector<ll>, greater<ll>> pq;

        rep(i, n) {
            cin >> a[i];
        }
        rep(i, n) {
            cin >> b[i];
            pq.push(b[i]);
        }

        sort(a.begin(), a.end());

        ll sumB = accumulate(b.begin(), b.begin() + k, 0LL);
        ll ans = LINF;

        rep(i, n-k+1){
            ans = min(ans, a[i+k-1]*sumB);
            if (!pq.empty()) {
                sumB -= pq.top();
                pq.pop();
                sumB += b[i];
                pq.push(b[i]);
            }
        } 

        cout << ans << '\n';
    }
}