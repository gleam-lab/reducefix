#include <iostream>
#include <vector>
#include <queue>
#include <algorithm>
using namespace std;
#define int long long

const int N = 2e5 + 9;
const int inf = 1e18;

pair<int, int> a[N], b[N];

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
            cin >> b[i].first;
            b[i].second = i;
        }
        
        sort(a, a + n);
        for (int i = 0; i < n; ++i) {
            b[i].first = b[a[i].second].first;
        }
        
        priority_queue<int> max_heap;
        int sum = 0;
        int ans = inf;
        
        for (int i = 0; i < n; ++i) {
            if (max_heap.size() < k - 1) {
                max_heap.push(b[i].first);
                sum += b[i].first;
            } else {
                if (k == 1) {
                    ans = min(ans, a[i].first * b[i].first);
                } else {
                    ans = min(ans, a[i].first * (sum + b[i].first));
                }
                if (b[i].first < max_heap.top()) {
                    sum -= max_heap.top();
                    max_heap.pop();
                    sum += b[i].first;
                    max_heap.push(b[i].first);
                }
            }
        }
        
        cout << ans << '\n';
    }
    return 0;
}