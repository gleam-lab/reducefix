#include <iostream>
#include <vector>
#include <queue>
#include <algorithm>
using namespace std;
#define int long long

const int N = 2e5 + 9;
const int inf = 1e18; // Use a sufficiently large value for infinity

pair<int, int> a[N];
int b[N];

signed main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    
    int t;
    cin >> t;
    while (t--) {
        int n, k;
        cin >> n >> k;
        for (int i = 0; i < n; ++i) {
            cin >> a[i].first;
            a[i].second = i;
        }
        for (int i = 0; i < n; ++i) {
            cin >> b[i];
        }
        
        // Sort based on A_i
        sort(a, a + n);
        
        // Rearrange B_i according to the sorted A_i
        vector<int> B(n);
        for (int i = 0; i < n; ++i) {
            B[i] = b[a[i].second];
        }
        
        int ans = inf;
        int sum = 0;
        priority_queue<int> pq; // max-heap to keep track of smallest K-1 elements
        
        for (int i = 0; i < n; ++i) {
            int current_A = a[i].first;
            int current_B = B[i];
            
            if (pq.size() < k - 1) {
                pq.push(current_B);
                sum += current_B;
            } else {
                if (!pq.empty() && current_B < pq.top()) {
                    sum -= pq.top();
                    pq.pop();
                    pq.push(current_B);
                    sum += current_B;
                }
            }
            
            if (pq.size() == k - 1) {
                ans = min(ans, current_A * (sum + current_B));
            }
        }
        
        cout << ans << '\n';
    }
    return 0;
}