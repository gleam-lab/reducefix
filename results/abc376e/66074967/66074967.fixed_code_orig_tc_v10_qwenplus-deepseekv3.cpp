#include <iostream>
#include <vector>
#include <algorithm>
#include <queue>
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
        
        priority_queue<int> pq;
        int sum = 0;
        int ans = inf;
        
        for (int i = 0; i < N; ++i) {
            int current_A = AB[i].first;
            int current_B = AB[i].second;
            
            if (pq.size() < K - 1) {
                pq.push(current_B);
                sum += current_B;
            } else {
                if (pq.size() > 0 && current_B < pq.top()) {
                    sum -= pq.top();
                    pq.pop();
                    pq.push(current_B);
                    sum += current_B;
                }
            }
            
            if (pq.size() == K - 1) {
                ans = min(ans, current_A * (sum + current_B));
            }
        }
        
        cout << ans << '\n';
    }
    return 0;
}