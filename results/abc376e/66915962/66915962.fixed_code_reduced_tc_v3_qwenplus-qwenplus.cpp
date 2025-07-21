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
    
    rep(qi, t){
        int n, k;
        cin >> n >> k;
        vector<P> pairs(n);
        
        // Read A values and store with index
        vector<pair<int, int>> a_with_index(n);
        rep(i, n) {
            cin >> a_with_index[i].first;
            a_with_index[i].second = i;
        }
        
        // Sort by A value
        sort(a_with_index.begin(), a_with_index.end());
        
        // Read B values
        vector<int> b(n);
        rep(i, n) cin >> b[i];
        
        ll sumB = 0;
        multiset<ll> b_values;
        
        // Initialize with first K elements
        rep(i, k) {
            sumB += b[a_with_index[i].second];
            b_values.insert(b[a_with_index[i].second]);
        }
        
        ll ans = a_with_index[k-1].first * sumB;
        
        // Process remaining elements
        rep2(i, k, n) {
            // Add current element's B value
            int idx = a_with_index[i].second;
            b_values.insert(b[idx]);
            sumB += b[idx];
            
            // Remove the largest B value in the set (maintain K smallest B values)
            auto it = prev(b_values.end());
            ll max_b = *it;
            b_values.erase(it);
            sumB -= max_b;
            
            // Update answer
            ans = min(ans, a_with_index[i].first * sumB);
        }
        
        cout << ans << '\n';
    }
    
    return 0;
}