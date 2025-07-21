#include <iostream>
#include <vector>
#include <algorithm>
#include <queue>
using namespace std;

#define int long long
const int N = 2e5 + 9;

int n, k;
vector<pair<int, int>> a, b;

int32_t main() {
    ios::sync_with_stdio(false);
    cin.tie(0);

    int T;
    cin >> T;
    while (T--) {
        cin >> n >> k;
        a.assign(n + 1, {0, 0});
        b.assign(n + 1, {0, 0});
        
        for (int i = 1; i <= n; ++i) {
            cin >> a[i].first;
            a[i].second = i;
        }
        for (int i = 1; i <= n; ++i) {
            cin >> b[i].first;
            b[i].second = i;
        }
        
        sort(a.begin() + 1, a.end());
        sort(b.begin() + 1, b.end());
        
        int res = LLONG_MAX;
        int s = 0;
        priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> pq;
        
        for (int i = 1; i <= n; ++i) {
            pq.push({b[i].first, a[i].first});
            s += b[i].first;
            if (pq.size() > k) {
                s -= pq.top().first;
                pq.pop();
            }
            if (i >= k - 1) {
                res = min(res, (s + b[i + 1].first) * a[i + 1].first);
            }
        }
        
        cout << res << '\n';
    }
    
    return 0;
}