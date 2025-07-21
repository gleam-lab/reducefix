#include <iostream>
#include <vector>
#include <queue>
using namespace std;

int main() {
    int t;
    cin >> t;
    while (t--) {
        int n, k;
        cin >> n >> k;
        vector<int> a(n), b(n);
        for (int i = 0; i < n; ++i) cin >> a[i];
        for (int i = 0; i < n; ++i) cin >> b[i];
        
        if (k == 1) {
            // For k = 1, the answer is simply the product of the first two largest elements
            cout << a[0] * b[0] << endl;
            continue;
        }
        
        sort(a.begin(), a.end(), greater<int>()); // Sort A in descending order
        sort(b.begin(), b.end()); // Sort B in ascending order
        
        // Priority queue for the smallest K-1 elements of B
        priority_queue<int, vector<int>, greater<int>> pq;
        long long sum_b = 0; // Sum of B elements in the current subset S
        int count = 0; // Number of elements in the current subset S
        
        long long ans = LLONG_MAX;
        
        for (int i = 0; i < n; ++i) {
            if (count < k) {
                pq.push(b[i]);
                sum_b += b[i];
                count++;
            } else {
                // Remove the element that will not be in the next subset
                sum_b -= pq.top();
                pq.pop();
                pq.push(b[i]);
                sum_b += b[i];
            }
            
            if (count == k) {
                ans = min(ans, (long long)a[i] * sum_b);
            }
        }
        
        cout << ans << endl;
    }
    return 0;
}