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
        vector<pair<int, int>> AB(N);
        for (int i = 0; i < N; ++i) {
            cin >> AB[i].first;
        }
        for (int i = 0; i < N; ++i) {
            cin >> AB[i].second;
        }
        
        sort(AB.begin(), AB.end());
        
        priority_queue<int> max_heap;
        int sum_B = 0;
        int min_product = inf;
        
        for (int i = 0; i < N; ++i) {
            int current_A = AB[i].first;
            int current_B = AB[i].second;
            int current_sum = sum_B + current_B;
            int current_product = current_A * current_sum;
            
            if (max_heap.size() == K - 1) {
                min_product = min(min_product, current_product);
            }
            
            max_heap.push(current_B);
            sum_B += current_B;
            
            if (max_heap.size() > K - 1) {
                sum_B -= max_heap.top();
                max_heap.pop();
            }
        }
        
        cout << min_product << '\n';
    }
    
    return 0;
}