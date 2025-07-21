#include <iostream>
#include <vector>
#include <queue>
#include <algorithm>
using namespace std;
#define int long long

const int N = 2e5 + 9;
const int inf = 0x3f3f3f3f3f3f3f3f;

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
        sort(a, a + n);
        for (int i = 0; i < n; ++i) {
            b[i] = b[a[i].second];
        }
        priority_queue<int, vector<int>, greater<int>> min_heap;
        int sum = 0;
        int ans = inf;
        for (int i = 0; i < n; ++i) {
            if (min_heap.size() < k - 1) {
                min_heap.push(b[i]);
                sum += b[i];
            } else {
                if (k == 1) {
                    ans = min(ans, a[i].first * b[i]);
                } else {
                    ans = min(ans, a[i].first * (sum + b[i]));
                    if (b[i] > min_heap.top()) {
                        sum -= min_heap.top();
                        min_heap.pop();
                        sum += b[i];
                        min_heap.push(b[i]);
                    }
                }
            }
        }
        cout << ans << '\n';
    }
    return 0;
}