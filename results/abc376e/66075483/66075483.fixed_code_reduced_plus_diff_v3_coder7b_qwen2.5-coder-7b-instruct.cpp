#include <iostream>
#include <vector>
#include <queue>
#include <algorithm>
using namespace std;

#define int long long
#define lowbit(x) x & (-x)

const int N = 2e5 + 9, inf = 0x3f3f3f3f3f3f3f3f;

int n, k, ans;
int s, q;
pair<int, int> a[N], b[N];

signed main() {
    ios::sync_with_stdio(false);
    cin.tie(0);

    int t;
    cin >> t;
    while (t--) {
        cin >> n >> k;
        
        for (int i = 1; i <= n; i++) {
            cin >> a[i].first;
            a[i].second = i;
        }
        
        for (int i = 1; i <= n; i++) {
            cin >> b[i].first;
            b[i].second = i;
        }
        
        sort(a + 1, a + n + 1, greater<pair<int, int>>());
        sort(b + 1, b + n + 1, greater<pair<int, int>>());

        priority_queue<int> pq;
        s = 0;
        for (int i = 1; i <= k; i++) {
            pq.push(b[i].first);
            s += b[i].first;
        }
        
        ans = pq.top() * a[1].first;
        
        for (int i = k + 1; i <= n; i++) {
            int newSum = s - pq.top() + b[i].first;
            pq.pop();
            pq.push(b[i].first);
            ans = min(ans, newSum * a[i].first);
            s = newSum;
        }

        cout << ans << endl;
    }
    
    return 0;
}