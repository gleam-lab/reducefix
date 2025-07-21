#include <iostream>
#include <vector>
#include <algorithm>
#include <queue>
using namespace std;
#define int long long

const int N = 2e5 + 9;
const int inf = 1e18;

pair<int, int> a[N], b[N];

signed main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    
    int t;
    cin >> t;
    while (t--) {
        int n, k;
        cin >> n >> k;
        for (int i = 0; i < n; i++) {
            cin >> a[i].first;
            a[i].second = i;
        }
        for (int i = 0; i < n; i++) {
            cin >> b[i].first;
            b[i].second = i;
        }
        
        // Sort based on A_i
        sort(a, a + n);
        
        // Create a new array with B_i in the same order as sorted A_i
        vector<int> B(n);
        for (int i = 0; i < n; i++) {
            B[i] = b[a[i].second].first;
        }
        
        int ans = inf;
        
        if (k == 1) {
            for (int i = 0; i < n; i++) {
                ans = min(ans, a[i].first * B[i]);
            }
        } else {
            priority_queue<int> pq;
            int sum = 0;
            
            for (int i = 0; i < n; i++) {
                if (pq.size() < k - 1) {
                    pq.push(B[i]);
                    sum += B[i];
                } else {
                    if (pq.size() && B[i] < pq.top()) {
                        sum -= pq.top();
                        pq.pop();
                        pq.push(B[i]);
                        sum += B[i];
                    }
                }
                
                if (pq.size() == k - 1 && i >= k - 2) {
                    ans = min(ans, a[i].first * (sum + B[i]));
                }
            }
        }
        
        cout << ans << '\n';
    }
    return 0;
}