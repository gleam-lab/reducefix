#include <iostream>
#include <vector>
#include <queue>
#include <algorithm>
using namespace std;
#define int long long

const int N = 2e5 + 9;
const int inf = 1e18;

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
        vector<int> B_sorted(n);
        for (int i = 0; i < n; ++i) {
            B_sorted[i] = b[a[i].second];
        }
        priority_queue<int> max_heap;
        int sum = 0;
        int ans = inf;
        for (int i = 0; i < n; ++i) {
            if (max_heap.size() < k - 1) {
                max_heap.push(B_sorted[i]);
                sum += B_sorted[i];
            } else {
                if (k == 1) {
                    ans = min(ans, a[i].first * B_sorted[i]);
                } else {
                    ans = min(ans, a[i].first * (sum + B_sorted[i]));
                }
                if (!max_heap.empty() && B_sorted[i] < max_heap.top()) {
                    sum -= max_heap.top();
                    max_heap.pop();
                    sum += B_sorted[i];
                    max_heap.push(B_sorted[i]);
                }
            }
        }
        cout << ans << '\n';
    }
    return 0;
}