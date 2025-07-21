#include <iostream>
#include <vector>
#include <algorithm>
#include <queue>
using namespace std;
using ll = long long;

int main() {
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
        
        // Sort by A_i in ascending order
        sort(elements.begin(), elements.end());
        
        ll min_product = LLONG_MAX;
        priority_queue<ll> pq; // Max-heap to store top K-1 B_i values
        
        ll sum = 0;
        
        for (int i = 0; i < N; i++) {
            ll current_A = elements[i].first;
            ll current_B = elements[i].second;
            
            // The current element will be the max A_i in the subset
            if (pq.size() == K-1) {
                min_product = min(min_product, current_A * (sum + current_B));
            }
            
            // Add current B_i to the heap and maintain size K-1
            if (pq.size() < K-1) {
                pq.push(current_B);
                sum += current_B;
            } else if (!pq.empty() && current_B < pq.top()) {
                sum -= pq.top();
                pq.pop();
                pq.push(current_B);
                sum += current_B;
            }
        }
        
        cout << min_product << '\n';
    }
    
    return 0;
}