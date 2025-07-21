#include <bits/stdc++.h>
using namespace std;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0);

    int t; cin >> t;
    while(t--) {
        int n, k; cin >> n >> k;
        vector<int> A(n), B(n);
        for(int i = 0; i < n; ++i) cin >> A[i];
        for(int i = 0; i < n; ++i) cin >> B[i];

        // Sort A in descending order
        sort(A.begin(), A.end(), greater<int>());
        // Sort B in descending order
        sort(B.begin(), B.end());

        // Min-heap to store the sums of pairs
        priority_queue<int, vector<int>, greater<int>> pq;

        // Initialize the heap with the smallest sums
        for(int i = 0; i < k; ++i) {
            pq.push(A[i] * B[n-k+i]);
        }

        // Iterate through the remaining elements
        for(int i = k; i < n; ++i) {
            int curr_max = pq.top();
            pq.pop();
            pq.push(curr_max + A[i] * B[n-k+i]);
        }

        // The top element of the heap is the result
        cout << pq.top() << '\n';
    }
    return 0;
}