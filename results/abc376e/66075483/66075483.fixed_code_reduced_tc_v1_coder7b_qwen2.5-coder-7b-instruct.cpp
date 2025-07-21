#include <iostream>
#include <vector>
#include <queue>
#include <algorithm>
using namespace std;

#define int long long
#define lowbit(x) x & (-x)

const int N = 2e5 + 9, inf = 0x3f3f3f3f3f3f3f3f;

int n, m, t, ans, k;
int s, q;
pair<int, int> a[N], b[N], bb[N];
bool vis[N];

signed main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    
    cin >> t;
    while (t--) {
        cin >> n >> k;
        for (int i = 1; i <= n; i++) {
            cin >> a[i].first;
            a[i].second = i;
        }
        for (int i = 1; i <= n; i++) {
            cin >> bb[i].first;
            bb[i].second = i;
        }
        
        // Sort based on A_i in descending order
        sort(a + 1, a + n + 1, greater<pair<int, int>>());
        
        // Create a sorted array of B_i indices based on A_i
        for (int i = 1; i <= n; i++) {
            b[i] = bb[a[i].second];
        }
        
        ans = inf;
        priority_queue<int> pq;
        s = 0;
        
        for (int i = 1; i <= n; i++) {
            pq.push(b[i].first);
            s += b[i].first;
            
            if (pq.size() > k) {
                s -= pq.top();
                pq.pop();
            }
            
            if (pq.size() == k) {
                ans = min(ans, (s + b[i].first) * a[i].first);
            }
        }
        
        cout << ans << endl;
    }
    
    return 0;
}