#include <bits/stdc++.h>
using namespace std;

typedef long long ll;

void solve() {
    int N, Q;
    cin >> N >> Q;
    
    vector<ll> A(N);
    for (int i = 0; i < N; ++i) {
        cin >> A[i];
    }
    
    // Sort the A array for binary search purposes
    sort(A.begin(), A.end());
    
    for (int q = 0; q < Q; ++q) {
        ll b;
        int k;
        cin >> b >> k;
        
        // We will use a min-heap to find the k-th smallest distance
        // Each heap element is a pair: (distance, index in A)
        priority_queue<pair<ll, int>> max_heap;
        
        // Initialize heap with first k elements
        for (int i = 0; i < k && i < N; ++i) {
            ll dist = abs(A[i] - b);
            max_heap.push({dist, i});
        }
        
        // Continue processing remaining elements
        for (int i = k; i < N; ++i) {
            ll dist = abs(A[i] - b);
            if (dist < max_heap.top().first) {
                max_heap.pop();
                max_heap.push({dist, i});
            }
        }
        
        // The top of the heap now contains the k-th smallest distance
        cout << max_heap.top().first << endl;
    }
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);
    
    solve();
    
    return 0;
}