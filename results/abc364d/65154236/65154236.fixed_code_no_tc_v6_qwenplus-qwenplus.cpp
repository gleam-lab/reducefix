#include <bits/stdc++.h>
using namespace std;

typedef long long ll;

const int MAXN = 1e5 + 5;

vector<ll> A;

// Binary search to find the k-th smallest distance from b
ll query(ll b, int k) {
    // Find the position where b would be inserted (first >= b)
    int pos = lower_bound(A.begin(), A.end(), b) - A.begin();
    
    int left = pos - 1;
    int right = pos;
    
    multiset<ll> distances;
    
    // We maintain at most k elements in the max-heap
    // Max-heap to keep track of the k smallest distances
    priority_queue<ll> max_heap;
    
    while (max_heap.size() < k) {
        ll left_dist = (left >= 0) ? abs(A[left] - b) : LLONG_MAX;
        ll right_dist = (right < A.size()) ? abs(A[right] - b) : LLONG_MAX;
        
        if (left_dist < right_dist) {
            max_heap.push(left_dist);
            left--;
        } else {
            max_heap.push(right_dist);
            right++;
        }
    }
    
    return max_heap.top();
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    
    int N, Q;
    cin >> N >> Q;
    
    A.resize(N);
    for (int i = 0; i < N; ++i) {
        cin >> A[i];
    }
    
    sort(A.begin(), A.end());
    
    while (Q--) {
        ll b;
        int k;
        cin >> b >> k;
        
        cout << query(b, k) << "\n";
    }
    
    return 0;
}