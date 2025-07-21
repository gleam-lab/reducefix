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
    
    int T;
    cin >> T;
    while (T--) {
        int N, K;
        cin >> N >> K;
        vector<pair<int, int>> elements(N);
        for (int i = 0; i < N; ++i) {
            cin >> elements[i].first;
        }
        for (int i = 0; i < N; ++i) {
            cin >> elements[i].second;
        }
        
        sort(elements.begin(), elements.end());
        
        priority_queue<int> max_heap;
        int sum = 0;
        vector<int> prefix_sum(N);
        
        for (int i = 0; i < N; ++i) {
            if (i < K) {
                max_heap.push(elements[i].second);
                sum += elements[i].second;
                if (i == K - 1) {
                    prefix_sum[i] = sum;
                }
            } else {
                if (elements[i].second < max_heap.top()) {
                    sum -= max_heap.top();
                    max_heap.pop();
                    sum += elements[i].second;
                    max_heap.push(elements[i].second);
                }
                prefix_sum[i] = sum;
            }
        }
        
        int min_val = inf;
        for (int i = K - 1; i < N; ++i) {
            if (i == K - 1) {
                min_val = min(min_val, elements[i].first * prefix_sum[i]);
            } else {
                min_val = min(min_val, elements[i].first * (prefix_sum[i - 1] + elements[i].second));
            }
        }
        
        cout << min_val << '\n';
    }
    
    return 0;
}