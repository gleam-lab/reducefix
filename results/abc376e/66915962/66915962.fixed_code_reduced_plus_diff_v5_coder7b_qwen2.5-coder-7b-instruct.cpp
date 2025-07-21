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
    while(t--){
        int n, k;
        cin >> n >> k;
        vector<ll> a(n), b(n);
        vector<P> p(n);
        rep(i, n) cin >> a[i];
        rep(i, n) cin >> b[i];
        
        // Sort A and B
        sort(a.begin(), a.end());
        sort(b.begin(), b.end());
        
        ll ans = LINF;
        ll sumB = 0;
        priority_queue<int, vector<int>, greater<int>> pq;
        
        // Initialize the first window of size k
        rep(i, k){
            sumB += b[i];
            pq.push(-b[i]); // Use negative because priority queue is max heap by default
        }
        
        // Calculate initial product
        ans = min(ans, a[k-1] * (-pq.top()) * sumB);
        
        // Slide the window across B
        rep2(i, k, n){
            sumB -= pq.top();
            pq.pop();
            sumB += b[i];
            pq.push(-b[i]);
            ans = min(ans, a[i] * (-pq.top()) * sumB);
        }
        
        cout << ans << '\n';
    }
}