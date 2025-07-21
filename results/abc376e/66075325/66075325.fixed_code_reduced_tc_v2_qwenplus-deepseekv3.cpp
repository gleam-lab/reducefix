#include <iostream>
#include <vector>
#include <queue>
#include <algorithm>
using namespace std;
#define int long long

const int N = 2e5 + 9;
const int inf = 0x3f3f3f3f3f3f3f3f;

pair<int, int> a[N], b[N];
int ans, s;

signed main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    
    int t;
    cin >> t;
    while (t--) {
        int n, k;
        cin >> n >> k;
        for (int i = 1; i <= n; i++) {
            cin >> a[i].first;
            a[i].second = i;
        }
        for (int i = 1; i <= n; i++) {
            cin >> b[i].first;
            b[i].second = i;
        }
        
        sort(a + 1, a + n + 1);
        for (int i = 1; i <= n; i++) {
            b[i].first = b[a[i].second].first;
        }
        
        ans = inf;
        s = 0;
        priority_queue<int> q;
        
        for (int i = 1; i <= n; i++) {
            if (q.size() < k - 1) {
                q.push(b[i].first);
                s += b[i].first;
            } else if (!q.empty() && b[i].first < q.top()) {
                s -= q.top();
                q.pop();
                q.push(b[i].first);
                s += b[i].first;
            }
            
            if (i >= k) {
                ans = min(ans, (s + b[i].first) * a[i].first);
            }
        }
        
        cout << ans << '\n';
    }
    
    return 0;
}