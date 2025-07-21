#include <iostream>
#include <vector>
#include <queue>
#include <algorithm>
using namespace std;
#define int long long
const int inf = 0x3f3f3f3f3f3f3f3f;

signed main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    int t;
    cin >> t;
    while (t--) {
        int n, k;
        cin >> n >> k;
        vector<pair<int, int>> pairs(n);
        for (int i = 0; i < n; ++i) {
            cin >> pairs[i].first;
        }
        for (int i = 0; i < n; ++i) {
            cin >> pairs[i].second;
        }
        sort(pairs.begin(), pairs.end());
        priority_queue<int> max_heap;
        int sum = 0;
        int ans = inf;
        for (int i = 0; i < n; ++i) {
            if (max_heap.size() < k - 1) {
                max_heap.push(pairs[i].second);
                sum += pairs[i].second;
            } else {
                if (k == 1) {
                    ans = min(ans, pairs[i].first * pairs[i].second);
                } else {
                    ans = min(ans, pairs[i].first * (sum + pairs[i].second));
                    if (pairs[i].second < max_heap.top()) {
                        sum -= max_heap.top();
                        max_heap.pop();
                        sum += pairs[i].second;
                        max_heap.push(pairs[i].second);
                    }
                }
            }
        }
        cout << ans << '\n';
    }
    return 0;
}