#include<bits/stdc++.h>
using namespace std;
typedef long long ll;

const int MAXN = 1e5 + 5;

int a[MAXN];

void solve() {
    int N, Q;
    cin >> N >> Q;
    
    // Read coordinates of A points
    for (int i = 0; i < N; i++) {
        cin >> a[i];
    }
    
    // Sort A points for efficient binary search
    sort(a, a + N);
    
    // Process each query
    for (int j = 0; j < Q; j++) {
        int b, k;
        cin >> b >> k;
        
        // We need to find the k-th smallest distance from b to any point in a
        
        // Create array of distances from b to all a[i]
        // But instead of computing all distances, we can use binary search on answer
        // However, simpler approach: find the k-th closest by considering candidates around b
        
        // Find position where b would be inserted in sorted array a
        auto it = lower_bound(a, a + N, b);
        int pos = it - a;
        
        // We'll consider elements around this position as candidates
        // The k-th closest must be among the k closest elements to b
        vector<int> candidates;
        
        // Add up to k elements to the left and right
        int left = pos - 1;
        int right = pos;
        
        // Get k closest points using two pointers
        while (candidates.size() < k && (left >= 0 || right < N)) {
            if (left >= 0 && (right >= N || abs(a[left] - b) <= abs(a[right] - b))) {
                candidates.push_back(abs(a[left] - b));
                left--;
            } else if (right < N) {
                candidates.push_back(abs(a[right] - b));
                right++;
            }
        }
        
        // Sort the distances to get the k-th smallest
        sort(candidates.begin(), candidates.end());
        
        cout << candidates[k-1] << endl;
    }
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    solve();
    return 0;
}