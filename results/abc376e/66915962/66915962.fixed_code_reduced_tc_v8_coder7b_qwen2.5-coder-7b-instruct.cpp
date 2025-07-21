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
    cout.tie(0);
    
    int t;
    cin >> t;
    while(t--){
        int n, k;
        cin >> n >> k;
        vector<ll> a(n), b(n);
        rep(i, n) cin >> a[i];
        rep(i, n) cin >> b[i];
        
        // Create a vector of pairs where each pair consists of an element from array A and its corresponding index
        vector<pair<ll, int>> ab(n);
        rep(i, n) ab[i] = {a[i], i};
        
        // Sort the pairs based on the elements of array A in descending order
        sort(ab.rbegin(), ab.rend());
        
        // Calculate the sum of the first k elements of array B and store their indices in a priority queue
        ll sumB = 0;
        priority_queue<int, vector<int>, greater<>> pq;
        rep(i, k){
            sumB += b[ab[i].second];
            pq.push(b[ab[i].second]);
        }
        
        // Initialize the answer with the product of the maximum element of the first k elements of array A and the sum of the first k elements of array B
        ll ans = ab[k-1].first * sumB;
        
        // Iterate over the remaining elements of array A
        rep2(i, k, n){
            // Remove the smallest element of the current subset of k elements of array B from the sum and add the next largest element
            sumB -= pq.top();
            pq.pop();
            sumB += b[ab[i].second];
            pq.push(b[ab[i].second]);
            
            // Update the answer if the new product is smaller
            ans = min(ans, ab[i].first * sumB);
        } 
        
        cout << ans << '\n';
    }
}