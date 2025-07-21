#include <iostream>
#include <vector>
#include <algorithm>
#include <queue>
using namespace std;
#define int long long

const int inf = 1e18;

struct Element {
    int a, b;
};

signed main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    
    int t;
    cin >> t;
    while (t--) {
        int n, k;
        cin >> n >> k;
        vector<Element> elements(n);
        for (int i = 0; i < n; i++) cin >> elements[i].a;
        for (int i = 0; i < n; i++) cin >> elements[i].b;
        
        // Sort elements by A in ascending order
        sort(elements.begin(), elements.end(), [](const Element& x, const Element& y) {
            return x.a < y.a;
        });
        
        // Priority queue to keep track of the smallest (k-1) B values
        priority_queue<int> pq;
        int sum = 0;
        int res = inf;
        
        for (int i = 0; i < n; i++) {
            // Current A is the maximum in the subset
            int current_max = elements[i].a;
            int current_sum = sum + elements[i].b;
            
            if (pq.size() == k-1) {
                res = min(res, current_max * current_sum);
            }
            
            // Add current B to the sum and priority queue
            pq.push(elements[i].b);
            sum += elements[i].b;
            
            // If we have more than k-1 elements, remove the largest B
            if (pq.size() > k-1) {
                sum -= pq.top();
                pq.pop();
            }
        }
        
        cout << res << '\n';
    }
    return 0;
}