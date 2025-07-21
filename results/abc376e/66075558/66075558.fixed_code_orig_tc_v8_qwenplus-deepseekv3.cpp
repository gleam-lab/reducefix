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
        vector<pair<int, int>> pairs(N);
        for (int i = 0; i < N; ++i) {
            cin >> pairs[i].first;
        }
        for (int i = 0; i < N; ++i) {
            cin >> pairs[i].second;
        }
        
        sort(pairs.begin(), pairs.end());
        
        priority_queue<int> pq;
        int sum = 0;
        int ans = inf;
        
        for (int i = 0; i < N; ++i) {
            int current_A = pairs[i].first;
            int current_B = pairs[i].second;
            
            if (pq.size() >= K) {
                if (current_B < pq.top()) {
                    sum -= pq.top();
                    pq.pop();
                    sum += current_B;
                    pq.push(current_B);
                }
            } else {
                sum += current_B;
                pq.push(current_B);
            }
            
            if (pq.size() == K) {
                ans = min(ans, current_A * sum);
            }
        }
        
        cout << ans << '\n';
    }
    return 0;
}