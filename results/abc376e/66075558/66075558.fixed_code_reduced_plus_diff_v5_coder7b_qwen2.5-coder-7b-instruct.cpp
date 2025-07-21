#include<iostream>
#include<vector>
#include<algorithm>
#include<queue>
using namespace std;

const int N = 2e5 + 9, inf = 0x3f3f3f3f;
int n, k;
vector<pair<int, int>> a, b;

signed main() {
    ios::sync_with_stdio(0), cin.tie(0), cout.tie(0);
    int T;
    cin >> T;
    while (T--) {
        cin >> n >> k;
        a.clear(), b.clear();
        for (int i = 0; i < n; ++i) {
            int x, y;
            cin >> x >> y;
            a.emplace_back(x, i);
            b.emplace_back(y, i);
        }
        sort(a.begin(), a.end());
        sort(b.begin(), b.end());

        int ans = inf, sum = 0;
        priority_queue<int> pq;
        for (int i = 0; i < k - 1; ++i) {
            sum += b[a[i].second].first;
            pq.push(b[a[i].second].first);
        }
        for (int i = k - 1; i < n; ++i) {
            sum += b[a[i].second].first;
            pq.push(b[a[i].second].first);
            ans = min(ans, sum * a[i].first);
            sum -= pq.top();
            pq.pop();
        }
        cout << ans << '\n';
    }
    return 0;
}