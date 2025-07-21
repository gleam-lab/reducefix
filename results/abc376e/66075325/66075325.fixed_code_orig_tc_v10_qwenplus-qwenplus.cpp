#include <iostream>
#include <vector>
#include <queue>
#include <algorithm>
using namespace std;

#define int long long

struct Item {
    int a, b;
};

signed main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    
    int T;
    cin >> T;
    
    while (T--) {
        int N, K;
        cin >> N >> K;
        
        vector<Item> items(N);
        for (int i = 0; i < N; ++i) {
            cin >> items[i].a;
        }
        for (int i = 0; i < N; ++i) {
            cin >> items[i].b;
        }
        
        // Sort by A in increasing order
        sort(items.begin(), items.end(), [](const Item& x, const Item& y) {
            return x.a < y.a;
        });
        
        // Min-heap to maintain the K smallest B values among first i+1 elements
        priority_queue<int, vector<int>, greater<>> pq;
        int sum_b = 0;
        int res = 1e18;  // Large initial value
        
        // We will keep at most K elements in the heap
        for (int i = 0; i < N; ++i) {
            pq.push(items[i].b);
            sum_b += items[i].b;
            
            if (pq.size() > K) {
                sum_b -= pq.top();
                pq.pop();
            }
            
            if (pq.size() == K) {
                res = min(res, items[i].a * sum_b);
            }
        }
        
        cout << res << "\n";
    }
    
    return 0;
}