#include <bits/stdc++.h>
using namespace std;

typedef long long ll;

const int MAXN = 1e5 + 5;

ll a[MAXN];

// Binary search to find the k-th smallest distance from b
ll query(ll b, ll k, int n) {
    // We will use two pointers to maintain a sliding window
    ll res;
    int left = 0, right = 0;
    
    // Sort the A array to enable binary search and sliding window
    sort(a, a + n);
    
    // Min heap to keep track of k-th smallest distances
    priority_queue<ll> max_heap;
    
    // Initialize heap with first k elements
    for (int i = 0; i < k; ++i) {
        ll dist = abs(a[i] - b);
        max_heap.push(dist);
    }
    
    // Slide window and update heap
    for (int i = k; i < n; ++i) {
        ll curr_dist = abs(a[i] - b);
        if (curr_dist < max_heap.top()) {
            max_heap.pop();
            max_heap.push(curr_dist);
        }
    }
    
    return max_heap.top();
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    
    int N, Q;
    cin >> N >> Q;
    
    for (int i = 0; i < N; ++i) {
        cin >> a[i];
    }
    
    for (int j = 0; j < Q; ++j) {
        ll b, k;
        cin >> b >> k;
        cout << query(b, k, N) << "\n";
    }
    
    return 0;
}