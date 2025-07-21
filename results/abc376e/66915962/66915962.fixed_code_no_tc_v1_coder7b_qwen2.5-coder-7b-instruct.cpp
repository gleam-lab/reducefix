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
        
        // Sort indices based on A values
        vector<int> idx(n);
        iota(idx.begin(), idx.end(), 0);
        sort(idx.begin(), idx.end(), [&](int i, int j){ return a[i] > a[j]; });
        
        // Select the top K elements for both A and B
        ll maxA = 0, sumB = 0;
        rep(i, k){
            maxA = max(maxA, a[idx[i]]);
            sumB += b[idx[i]];
        }
        
        // Calculate the initial result
        ll ans = maxA * sumB;
        
        // Try to improve the result by replacing one element at a time
        rep2(i, 1, k+1){
            int replace_idx = idx[i-1];
            ll new_maxA = max(maxA, a[idx[i]]);
            ll new_sumB = sumB + b[idx[i]] - b[replace_idx];
            ans = min(ans, new_maxA * new_sumB);
        }
        
        cout << ans << '\n';
    }
}