#include <iostream>
#include <vector>
#include <algorithm>
#include <queue>
using namespace std;
#define int long long

signed main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    
    int t;
    cin >> t;
    while (t--) {
        int n, k;
        cin >> n >> k;
        vector<pair<int, int>> ab(n);
        for (int i = 0; i < n; i++) cin >> ab[i].first;
        for (int i = 0; i < n; i++) cin >> ab[i].second;
        
        sort(ab.begin(), ab.end());
        
        vector<int> suffix_sum(n + 1);
        for (int i = n - 1; i >= 0; i--) {
            suffix_sum[i] = suffix_sum[i + 1] + ab[i].second;
        }
        
        priority_queue<int, vector<int>, greater<int>> min_heap;
        int current_sum = 0;
        int min_val = 1LL << 60;
        
        for (int i = 0; i < n; i++) {
            if (min_heap.size() < k - 1) {
                min_heap.push(ab[i].second);
                current_sum += ab[i].second;
            } else {
                if (k == 1) {
                    min_val = min(min_val, ab[i].first * ab[i].second);
                } else {
                    int total = current_sum + ab[i].second;
                    min_val = min(min_val, ab[i].first * total);
                    
                    if (!min_heap.empty() && ab[i].second > min_heap.top()) {
                        current_sum -= min_heap.top();
                        min_heap.pop();
                        current_sum += ab[i].second;
                        min_heap.push(ab[i].second);
                    }
                }
            }
        }
        
        cout << min_val << '\n';
    }
    return 0;
}