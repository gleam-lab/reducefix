#include <iostream>
#include <vector>
#include <algorithm>
#include <queue>
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
        vector<pair<int, int>> elements(N);
        for (int i = 0; i < N; i++) {
            cin >> elements[i].first;
        }
        for (int i = 0; i < N; i++) {
            cin >> elements[i].second;
        }
        
        sort(elements.begin(), elements.end());
        
        priority_queue<int> pq;
        int sum = 0;
        vector<int> max_left(N);
        
        for (int i = 0; i < N; i++) {
            pq.push(elements[i].second);
            sum += elements[i].second;
            
            if (pq.size() > K) {
                sum -= pq.top();
                pq.pop();
            }
            
            if (pq.size() == K) {
                max_left[i] = sum;
            } else {
                max_left[i] = -INF;
            }
        }
        
        int ans = INF;
        sum = 0;
        while (!pq.empty()) pq.pop();
        
        for (int i = N-1; i >= 0; i--) {
            pq.push(elements[i].second);
            sum += elements[i].second;
            
            if (pq.size() > K) {
                sum -= pq.top();
                pq.pop();
            }
            
            if (pq.size() == K && i > 0) {
                int current = elements[i].first * (sum + max_left[i-1]);
                if (current < ans) {
                    ans = current;
                }
            }
        }
        
        // Special case when K = 1
        if (K == 1) {
            ans = INF;
            for (int i = 0; i < N; i++) {
                int current = elements[i].first * elements[i].second;
                if (current < ans) {
                    ans = current;
                }
            }
        }
        
        cout << ans << '\n';
    }
    return 0;
}