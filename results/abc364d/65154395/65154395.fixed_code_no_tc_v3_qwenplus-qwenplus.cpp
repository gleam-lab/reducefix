#include <bits/stdc++.h>
using namespace std;

typedef long long ll;

void solve() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    
    int N, Q;
    cin >> N >> Q;
    
    vector<ll> A(N);
    for (int i = 0; i < N; ++i) {
        cin >> A[i];
    }
    
    // Sort the A array for binary search operations
    sort(A.begin(), A.end());
    
    for (int q = 0; q < Q; ++q) {
        ll b;
        int k;
        cin >> b >> k;
        
        // Binary search to find the k-th closest element
        // We'll use a custom comparator to find distances from b
        auto cmp = [b](ll x, ll y) {
            return abs(x - b) < abs(y - b);
        };
        
        // Since we can't directly sort by distance for each query efficiently,
        // we'll use a max-heap of size k to keep track of the k smallest distances
        priority_queue<pair<ll, ll>> max_heap; // (distance, value)
        
        // Binary search boundaries
        int left = 0;
        int right = N - 1;
        int pos = -1;
        
        // Find the position in A where the element is closest to b
        while (left <= right) {
            int mid = (left + right) / 2;
            if (A[mid] <= b) {
                left = mid + 1;
                pos = mid;
            } else {
                right = mid - 1;
            }
        }
        
        // Now we have a sorted array and the position where b would be inserted
        // Use two pointers to get the k-th closest element
        int i = pos;
        int j = pos + 1;
        int count = 0;
        ll result = 0;
        
        while (count < k && (i >= 0 || j < N)) {
            if (i < 0) {
                result = abs(A[j++] - b);
            } else if (j >= N) {
                result = abs(A[i--] - b);
            } else if (abs(A[i] - b) <= abs(A[j] - b)) {
                result = abs(A[i--] - b);
            } else {
                result = abs(A[j++] - b);
            }
            count++;
        }
        
        cout << result << '\n';
    }
}

int main() {
    solve();
    return 0;
}