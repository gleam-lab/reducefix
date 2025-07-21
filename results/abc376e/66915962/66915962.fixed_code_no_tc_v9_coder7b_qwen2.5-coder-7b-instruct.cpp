#include<bits/stdc++.h>
using namespace std;
using ll = long long;
using VI = vector<int>;
using P = pair<int, int>;
constexpr int INF = 1001001001;
constexpr ll LINF = 1001001001001001001ll;

int main(){
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    
    int t;
    cin >> t;
    // vector<vector<int>> v(n, vector<int>(m));

    while(t--){
        int n, k;
        cin >> n >> k;
        vector<ll> a(n), b(n);
        vector<P> p(n);
        
        // Read input into pairs
        rep(i, n) {
            cin >> a[i];
            cin >> b[i];
            p[i] = {a[i], b[i]};
        }
        
        // Sort by a_i first, then by b_i if a_i are equal
        sort(p.begin(), p.end());
        
        // Extract sorted a_i and b_i into separate vectors
        rep(i, n) {
            a[i] = p[i].first;
            b[i] = p[i].second;
        }
        
        // Initialize variables
        ll ans = LINF;
        ll sumB = 0;
        priority_queue<ll, vector<ll>, greater<ll>> pq;
        
        // Calculate initial sum of smallest K elements of b_i
        rep(i, k) {
            pq.push(-b[i]); // Using negative because priority queue is max heap by default
            sumB -= b[i];
        }
        
        // Calculate the initial product
        ans = min(ans, a[k-1] * (-sumB)); // Convert back to positive
        
        // Sliding window to find the minimum product
        rep2(i, k, n) {
            sumB += b[i];
            sumB += pq.top(); // Add the smallest element removed by the previous step
            pq.pop();
            pq.push(-b[i]); // Add the new element
            
            ans = min(ans, a[i] * (-sumB)); // Convert back to positive
        } 
        
        cout << ans << '\n';
    }
}