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
    
    rep(qi, t){
        int n, k;
        cin >> n >> k;
        vector<ll> a(n), b(n);
        
        rep(i, n) cin >> a[i];
        rep(i, n) cin >> b[i];
        
        sort(a.begin(), a.end());
        sort(b.begin(), b.end());
        
        ll ans = LINF;
        ll sumB = accumulate(b.begin(), b.begin() + k, 0LL);
        
        for(int i = 0; i <= n - k; i++){
            ans = min(ans, a[i + k - 1] * sumB);
            if(i + k < n){
                sumB -= b[i];
                sumB += b[i + k];
            }
        }
        
        cout << ans << '\n';
    }
}