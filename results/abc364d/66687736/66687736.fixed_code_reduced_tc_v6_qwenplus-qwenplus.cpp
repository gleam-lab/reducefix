#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define rep(i,n) for(int i=0;i<(int)n;i++)
#define vi vector<int>
#define vl vector<ll>
#define vpi vector<pair<int, int>>

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    
    int N, Q;
    cin >> N >> Q;
    
    vi A(N);
    for (int i = 0; i < N; ++i) {
        cin >> A[i];
    }
    
    // Sort A for binary search usage
    sort(A.begin(), A.end());
    
    // Process each query
    for (int q = 0; q < Q; ++q) {
        int b, k;
        cin >> b >> k;
        
        // Create a lambda to compute distance
        auto dist = [&](int x) {
            return abs(x - b);
        };
        
        // We'll use a max-heap to keep track of the k smallest distances
        priority_queue<pair<int, int>> pq; // Max-heap (distance, value)
        
        // Binary search approach won't work for k-th smallest directly
        // So we use a heap approach
        
        // Using two pointers from ends of the sorted array
        int left = 0, right = N - 1;
        int count = 0;
        
        while (count < k && left <= right) {
            int dl = abs(A[left] - b);
            int dr = abs(A[right] - b);
            
            if (dl <= dr) {
                if (pq.size() < k || dl < pq.top().first) {
                    if (pq.size() == k) pq.pop();
                    pq.emplace(dl, A[left]);
                }
                left++;
            } else {
                if (pq.size() < k || dr < pq.top().first) {
                    if (pq.size() == k) pq.pop();
                    pq.emplace(dr, A[right]);
                }
                right--;
            }
            count++;
        }
        
        cout << pq.top().first << "\n";
    }
}