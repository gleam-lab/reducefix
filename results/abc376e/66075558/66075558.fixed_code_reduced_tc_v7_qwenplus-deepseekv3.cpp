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
        vector<pair<int, int>> elements(n);
        for (int i = 0; i < n; i++) {
            cin >> elements[i].first;
        }
        for (int i = 0; i < n; i++) {
            cin >> elements[i].second;
        }
        
        sort(elements.begin(), elements.end());
        
        priority_queue<int> pq;
        int sum = 0;
        int min_val = inf;
        
        for (int i = 0; i < n; i++) {
            int current_A = elements[i].first;
            int current_B = elements[i].second;
            
            if (pq.size() < k - 1) {
                pq.push(current_B);
                sum += current_B;
            } else {
                if (k == 1) {
                    min_val = min(min_val, current_A * current_B);
                } else {
                    int total = sum + current_B;
                    min_val = min(min_val, current_A * total);
                    
                    if (!pq.empty() && current_B < pq.top()) {
                        sum -= pq.top();
                        pq.pop();
                        sum += current_B;
                        pq.push(current_B);
                    }
                }
            }
        }
        
        cout << min_val << '\n';
    }
    
    return 0;
}