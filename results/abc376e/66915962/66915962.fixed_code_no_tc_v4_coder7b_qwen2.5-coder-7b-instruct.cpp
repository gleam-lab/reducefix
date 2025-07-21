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
    
    while(t--){
        int n, k;
        cin >> n >> k;
        vector<ll> a(n), b(n);
        
        rep(i, n) cin >> a[i];
        rep(i, n) cin >> b[i];
        
        sort(a.begin(), a.end());
        sort(b.begin(), b.end(), greater<ll>());
        
        ll maxA = a[k-1];
        ll sumB = accumulate(b.begin(), b.begin() + k, 0LL);
        
        ll ans = maxA * sumB;
        
        rep2(i, k, n){
            sumB -= b[i-k];
            sumB += b[i];
            ans = min(ans, maxA * sumB);
        }
        
        cout << ans << '\n';
    }
}