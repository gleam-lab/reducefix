#include<bits/stdc++.h>
using namespace std;
typedef long long ll;

const int MAXN = 1e5 + 5;

int a[MAXN];

void solve() {
    int N, Q;
    cin >> N >> Q;
    
    // Read the A points
    for (int i = 0; i < N; i++) {
        cin >> a[i];
    }
    
    // Sort the A array to enable binary search around B_j
    sort(a, a + N);
    
    // Process each query
    for (int j = 0; j < Q; j++) {
        int b, k;
        cin >> b >> k;
        
        // Find the position where b would be inserted
        auto it = lower_bound(a, a + N, b);
        int pos = it - a;
        
        // We'll consider elements from both left and right of b
        // Create a list of distances by expanding outward from pos
        vector<int> distances;
        
        // Add distances from elements >= b (starting at pos)
        for (int i = pos; i < N; i++) {
            distances.push_back(abs(a[i] - b));
        }
        
        // Add distances from elements < b (going backward from pos-1)
        for (int i = pos - 1; i >= 0; i--) {
            distances.push_back(abs(a[i] - b));
        }
        
        // The k-th smallest distance is at index k-1
        cout << distances[k - 1] << '\n';
    }
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    
    solve();
    
    return 0;
}