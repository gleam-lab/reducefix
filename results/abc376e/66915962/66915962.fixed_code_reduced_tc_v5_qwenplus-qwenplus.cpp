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
        vector<pair<ll, ll>> items(n);
        
        rep(i, n) cin >> items[i].first;  // A_i
        rep(i, n) cin >> items[i].second; // B_i
        
        // Sort by A_i ascending
        sort(items.begin(), items.end());
        
        ll sumB = 0;
        multiset<ll> bSet;
        
        // Initialize with first K elements
        rep(i, k) {
            sumB += items[i].second;
            bSet.insert(items[i].second);
        }
        
        ll ans = items[k-1].first * sumB;
        
        rep2(i, k, n) {
            // We want to remove the largest B value in the current set
            // Because we're minimizing max(A) * sum(B), and A is sorted,
            // so A[i] will be increasing. So to improve result, we need to keep small B's.
            // Therefore, remove the largest B currently in the set
            
            ll maxB = *prev(bSet.end());
            sumB -= maxB;
            bSet.erase(prev(bSet.end()));
            
            // Add new B
            sumB += items[i].second;
            bSet.insert(items[i].second);
            
            // Current max A is items[i].first since we process in order
            ans = min(ans, items[i].first * sumB);
        }
        
        cout << ans << '\n';
    }
}