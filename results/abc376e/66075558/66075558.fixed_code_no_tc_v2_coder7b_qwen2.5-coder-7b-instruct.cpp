#include <iostream>
#include <vector>
#include <queue>
#include <algorithm>
using namespace std;

#define ll long long

const int MAXN = 2e5 + 9;
const int INF = 0x3f3f3f3f3f3f3f3f;

ll n, k, t;
pair<ll, ll> a[MAXN], b[MAXN];

// Comparator function to sort pairs based on first element
bool cmp(const pair<ll, ll>& pa, const pair<ll, ll>& pb) {
    return pa.first == pb.first ? a[pa.second].first > a[pb.second].first : pa.first > pb.first;
}

signed main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    
    cin >> t;
    while (t--) {
        cin >> n >> k;
        
        // Read A array and store indices
        for (int i = 1; i <= n; ++i) {
            cin >> a[i].first;
            a[i].second = i;
        }
        
        // Sort A based on the first element in descending order
        sort(a + 1, a + n + 1, cmp);
        
        // Read B array
        for (int i = 1; i <= n; ++i) {
            cin >> b[i].first;
        }
        
        // Initialize variables
        ll ans = INF, sum = 0;
        priority_queue<ll> pq;
        
        // Iterate through sorted A
        for (int i = 1; i <= n; ++i) {
            pq.push(b[i]);
            sum += b[i];
            
            // Maintain a window of size k-1 elements
            while (pq.size() > k) {
                sum -= pq.top();
                pq.pop();
            }
            
            // If we have enough elements in the window, calculate the current score
            if (i >= k) {
                ans = min(ans, sum * a[i].first);
            }
        }
        
        cout << ans << '\n';
    }
    
    return 0;
}