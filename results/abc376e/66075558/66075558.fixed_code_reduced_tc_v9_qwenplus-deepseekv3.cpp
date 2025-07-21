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
        vector<pair<int, int>> A(N);
        vector<int> B(N);
        for (int i = 0; i < N; ++i) {
            cin >> A[i].first;
            A[i].second = i;
        }
        for (int i = 0; i < N; ++i) {
            cin >> B[i];
        }
        
        sort(A.begin(), A.end());
        
        vector<int> sorted_B(N);
        for (int i = 0; i < N; ++i) {
            sorted_B[i] = B[A[i].second];
        }
        
        priority_queue<int> max_heap;
        int sum_B = 0;
        int min_val = inf;
        
        for (int i = 0; i < N; ++i) {
            int current_A = A[i].first;
            int current_B = sorted_B[i];
            
            if (i >= K) {
                if (max_heap.top() > current_B) {
                    sum_B -= max_heap.top();
                    max_heap.pop();
                    sum_B += current_B;
                    max_heap.push(current_B);
                }
            } else {
                sum_B += current_B;
                max_heap.push(current_B);
            }
            
            if (i >= K - 1) {
                min_val = min(min_val, current_A * sum_B);
            }
        }
        
        cout << min_val << '\n';
    }
    
    return 0;
}