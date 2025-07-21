#include <iostream>
#include <vector>
#include <queue>
#include <algorithm>
using namespace std;
#define int long long

const int INF = 1e18;

signed main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    
    int T;
    cin >> T;
    while (T--) {
        int N, K;
        cin >> N >> K;
        vector<pair<int, int>> pairs(N);
        for (int i = 0; i < N; ++i) {
            cin >> pairs[i].first;
        }
        for (int i = 0; i < N; ++i) {
            cin >> pairs[i].second;
        }
        
        sort(pairs.begin(), pairs.end());
        
        priority_queue<int, vector<int>, greater<int>> min_heap;
        int sum = 0;
        int min_product = INF;
        
        for (int i = N - 1; i >= 0; --i) {
            int current_A = pairs[i].first;
            int current_B = pairs[i].second;
            
            if (min_heap.size() < K - 1) {
                min_heap.push(current_B);
                sum += current_B;
            } else if (!min_heap.empty() && current_B > min_heap.top()) {
                sum -= min_heap.top();
                min_heap.pop();
                min_heap.push(current_B);
                sum += current_B;
            }
            
            if (min_heap.size() == K - 1) {
                int current_sum = sum + current_B;
                int current_product = current_A * current_sum;
                if (current_product < min_product) {
                    min_product = current_product;
                }
            }
        }
        
        cout << min_product << '\n';
    }
    
    return 0;
}