#include <bits/stdc++.h>
using namespace std;

typedef long long ll;

const int OFFSET = 100000000; // To handle negative indices

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    
    int N, Q;
    cin >> N >> Q;
    
    vector<int> freq(200000001, 0); // Range from -1e8 to 1e8 (with offset)

    // Read all A values and update frequency count
    for (int i = 0; i < N; ++i) {
        int a;
        cin >> a;
        freq[a + OFFSET]++;
    }
    
    // Prefix sum to support range queries
    vector<ll> prefix(200000002, 0);
    for (int i = 0; i <= 200000000; ++i) {
        prefix[i + 1] = prefix[i] + freq[i];
    }

    // Process each query
    for (int i = 0; i < Q; ++i) {
        int b, k;
        cin >> b >> k;
        
        // Binary search on distance d
        int left = 0, right = 200000000;
        while (left < right) {
            int mid = (left + right) / 2;
            
            // Determine how many points are within distance mid of b
            int l = max(0, b - mid + OFFSET);
            int r = min(200000000, b + mid + OFFSET);
            ll count = prefix[r + 1] - prefix[l];
            
            if (count >= k)
                right = mid;
            else
                left = mid + 1;
        }
        
        cout << left << "\n";
    }

    return 0;
}