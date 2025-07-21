#include <bits/stdc++.h>
using namespace std;

typedef long long ll;

void solve() {
    int N, Q;
    cin >> N >> Q;
    
    vector<int> a(N);
    for (int i = 0; i < N; ++i) {
        cin >> a[i];
    }
    
    // Sort the A array for binary searching later
    sort(a.begin(), a.end());
    
    for (int q = 0; q < Q; ++q) {
        int b_j, k_j;
        cin >> b_j >> k_j;
        
        // Use binary search to find the position in A closest to B_j
        int pos = lower_bound(a.begin(), a.end(), b_j) - a.begin();
        
        // We'll use a min-heap to find the k-th smallest distance
        priority_queue<pair<int, int>, vector<pair<int, int>>, greater<>> pq;
        
        // Initialize pointers
        int left = pos - 1;
        int right = pos;
        
        // Add initial candidates
        if (left >= 0) pq.emplace(abs(a[left] - b_j), left);
        if (right < N) pq.emplace(abs(a[right] - b_j), right);
        
        // To avoid revisiting elements
        vector<bool> visited(N, false);
        
        int count = 0;
        int result = -1;
        
        while (!pq.empty()) {
            auto [dist, idx] = pq.top();
            pq.pop();
            
            if (visited[idx]) continue;
            visited[idx] = true;
            
            count++;
            if (count == k_j) {
                result = dist;
                break;
            }
            
            // Move pointers and add next candidates
            if (idx > 0 && !visited[idx - 1]) {
                pq.emplace(abs(a[idx - 1] - b_j), idx - 1);
            }
            if (idx < N - 1 && !visited[idx + 1]) {
                pq.emplace(abs(a[idx + 1] - b_j), idx + 1);
            }
        }
        
        cout << result << endl;
    }
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);
    
    solve();
    return 0;
}