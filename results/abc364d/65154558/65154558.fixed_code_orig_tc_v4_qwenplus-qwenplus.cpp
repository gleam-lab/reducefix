#include <bits/stdc++.h>
using namespace std;

typedef long long ll;

const int OFFSET = 100000000; // To handle negative indices
const int MAX_COORD = 200000000 + 5; // Since range is [-1e8, 1e8]

int freq[MAX_COORD * 2 + 10]; // Frequency array for coordinates

// Binary search to find the k-th smallest distance
ll findKthDistance(int b, int k) {
    int left = b - OFFSET;
    int right = b + OFFSET;
    
    while (true) {
        int mid = (left + right) / 2;
        int total = 0;
        
        // Count how many points are within distance <= mid
        int l = max(OFFSET, b - mid);
        int r = min(OFFSET + MAX_COORD, b + mid);
        
        total = freq[r] - freq[l - 1];
        
        if (total >= k) {
            return mid;
        } else {
            if (b - l > r - b) {
                // More elements on the left, move left bound
                l--;
            } else {
                // More elements on the right, move right bound
                r++;
            }
        }
    }
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    
    int N, Q;
    cin >> N >> Q;
    
    vector<ll> a(N);
    for (int i = 0; i < N; ++i) {
        cin >> a[i];
        freq[a[i] + OFFSET]++; // Shift coordinate to non-negative index
    }
    
    // Build prefix sum array
    for (int i = 1; i < MAX_COORD * 2 + 5; ++i) {
        freq[i] += freq[i - 1];
    }
    
    for (int q = 0; q < Q; ++q) {
        int b, k;
        cin >> b >> k;
        
        // Binary search boundaries
        int low = 0;
        int high = 200000000;
        
        while (low < high) {
            int mid = (low + high) / 2;
            
            // Calculate how many points are within distance <= mid from b
            int l = max(-OFFSET, b - mid) + OFFSET;
            int r = min(OFFSET, b + mid) + OFFSET;
            
            int count = freq[r] - (l > 0 ? freq[l - 1] : 0);
            
            if (count >= k) {
                high = mid;
            } else {
                low = mid + 1;
            }
        }
        
        cout << low << "\n";
    }
    
    return 0;
}