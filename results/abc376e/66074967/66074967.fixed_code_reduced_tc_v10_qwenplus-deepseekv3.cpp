#include <iostream>
#include <vector>
#include <queue>
#include <algorithm>
using namespace std;
#define int long long
const int inf = 1e18;

signed main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    int t;
    cin >> t;
    while (t--) {
        int n, k;
        cin >> n >> k;
        vector<pair<int, int>> a_b(n);
        for (int i = 0; i < n; ++i) {
            cin >> a_b[i].first;
        }
        for (int i = 0; i < n; ++i) {
            cin >> a_b[i].second;
        }
        sort(a_b.begin(), a_b.end());
        
        priority_queue<int> max_heap;
        int sum_b = 0;
        int min_value = inf;
        
        for (int i = 0; i < n; ++i) {
            int current_a = a_b[i].first;
            int current_b = a_b[i].second;
            
            if (max_heap.size() < k - 1) {
                max_heap.push(current_b);
                sum_b += current_b;
            } else if (!max_heap.empty() && current_b < max_heap.top()) {
                sum_b -= max_heap.top();
                max_heap.pop();
                max_heap.push(current_b);
                sum_b += current_b;
            }
            
            if (max_heap.size() == k - 1) {
                int current_sum = sum_b + current_b;
                min_value = min(min_value, current_a * current_sum);
            }
        }
        cout << min_value << '\n';
    }
    return 0;
}