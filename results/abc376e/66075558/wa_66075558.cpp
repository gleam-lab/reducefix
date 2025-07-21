#include<iostream>
#include<vector>
#include<queue>
#include<stack>
#include"algorithm"
using namespace std;
#define int long long
#define lowbit(x) x&(-x)
const int N = 2e5 + 9, inf = 0x3f3f3f3f3f3f3f3f;
int n, m, t, ans, k;
int s, q;
pair<int, int>a[N], b[N], bb[N];
bool vis[N];
bool cmp(pair<int, int>pa, pair<int, int>pb) {
    return pa.first == pb.first ? b[pa.second] < b[pb.second] : pa.first < pb.first;
}
signed main() {
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
        sort(a + 1, a + n + 1,cmp);
        for (int i = 1; i <= n; i++) {
            b[i] = bb[a[i].second];
        }
        ans = inf; s = 0; priority_queue<int>q;
        for (int i = 1; i < n; i++) {
            q.push(b[i].first);
            s += b[i].first;
            while (q.size() >= k) {
                s -= q.top(); q.pop();
            }
            if (i >= k - 1)
                ans = min(ans, (s + b[i + 1].first) * a[i + 1].first);

        }

        cout << ans << endl;
    }
    return 0;
}
