#include <iostream>
#include <vector>
#include <queue>
#include <algorithm>
using namespace std;

int compare(const pair<int, int>& a, const pair<int, int>& b) {
    return a.second > b.second;
}

int main() {
    int t;
    cin >> t;
    while (t--) {
        int n, k;
        cin >> n >> k;
        vector<int> A(n + 1);
        vector<int> B(n + 1);
        
        for (int i = 1; i <= n; ++i) {
            cin >> A[i];
        }
        for (int i = 1; i <= n; ++i) {
            cin >> B[i];
        }
        
        priority_queue<pair<int, int>, vector<pair<int, int>>, compare> minHeap;
        int ans = INT_MAX;
        
        for (int i = 0; i < n; ++i) {
            minHeap.push({A[i], B[i]});
        }
        
        while (k-- > 0) {
            int maxA = minHeap.top().first;
            int sumB = 0;
            vector<int> b_values;
            
            for (int j = 0; j < k; ++j) {
                sumB += minHeap.top().second;
                b_values.push_back(minHeap.top().second);
                minHeap.pop();
            }
            
            // Calculate the sum of the remaining elements of B
            int remainingSumB = 0;
            for (int j = 0; j < n; ++j) {
                if (!binary_search(b_values.begin(), b_values.end(), B[j])) {
                    remainingSumB += B[j];
                }
            }
            
            ans = min(ans, maxA * (sumB + remainingSumB));
            
            // Add the next largest element in A
            minHeap.push({A[n - (k - j - 1)], B[n - (k - j - 1)]});
        }
        
        cout << ans << endl;
    }
    
    return 0;
}