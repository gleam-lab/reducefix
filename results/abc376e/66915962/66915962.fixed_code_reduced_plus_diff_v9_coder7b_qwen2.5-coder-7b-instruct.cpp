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

int main() {
    int t;
    cin >> t;
    
    while(t--) {
        int n, k;
        cin >> n >> k;
        
        vector<ll> a(n), b(n);
        rep(i, n) cin >> a[i];
        rep(i, n) cin >> b[i];
        
        // Sort based on A values in descending order
        vector<pair<ll, ll>> ab(n);
        rep(i, n) ab[i] = {a[i], b[i]};
        sort(ab.rbegin(), ab.rend());
        
        // Min-heap to keep track of the smallest B values
        priority_queue<ll, vector<ll>, greater<ll>> pq;
        ll sumB = 0;
        
        // Add first K elements to the heap and calculate their sum
        rep(i, k) {
            pq.push(ab[i].second);
            sumB += ab[i].second;
        }
        
        // Initialize the result with the current product
        ll ans = pq.top() * sumB;
        
        // Iterate through the remaining elements
        rep2(i, k, n) {
            ll smax = pq.top();
            pq.pop();
            pq.push(ab[i].second);
            sumB -= smax;
            sumB += ab[i].second;
            
            ans = min(ans, pq.top() * sumB);
        }
        
        cout << ans << '\n';
    }
    
    return 0;
}