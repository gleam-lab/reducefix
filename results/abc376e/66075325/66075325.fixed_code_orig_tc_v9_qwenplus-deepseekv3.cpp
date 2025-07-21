#include<iostream>
#include<vector>
#include<queue>
#include<algorithm>
using namespace std;
#define int long long
#define lowbit(x) x&(-x)
const int N = 2e5 + 9, inf = 0x3f3f3f3f3f3f3f3f;
int n, m, t, ans, k;
int s, q;
pair<int, int> a[N], b[N], bb[N];
bool vis[N];

signed main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
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
        sort(a + 1, a + n + 1);
        for (int i = 1; i <= n; i++) {
            b[i].first = bb[a[i].second].first;
            b[i].second = a[i].second;
        }
        ans = inf;
        s = 0;
        priority_queue<int> q;
        for (int i = 1; i <= n; i++) {
            if (q.size() < k - 1) {
                q.push(b[i].first);
                s += b[i].first;
            } else {
                if (k > 1 && b[i].first < q.top()) {
                    s -= q.top();
                    q.pop();
                    q.push(b[i].first);
                    s += b[i].first;
                }
            }
            if (i >= k) {
                ans = min(ans, (s + b[i].first) * a[i].first);
            }
        }
        cout << ans << '\n';
    }
    return 0;
}