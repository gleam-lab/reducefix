#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int main() {
    int N, Q;
    cin >> N >> Q;
    vector<int> a(N);
    vector<int> sorted_a;
    
    // Read and sort the point coordinates
    for (int i = 0; i < N; i++) {
        cin >> a[i];
        sorted_a.push_back(a[i]);
    }
    sort(sorted_a.begin(), sorted_a.end());
    
    // Create a cumulative count array
    vector<int> count(N + 1, 0);
    for (int i = 0; i < N; i++) {
        count[a[i]] = i + 1; // +1 because we need 1-based indexing for k-th element
    }
    
    // Prefix sum to make count[i] the number of elements <= i
    for (int i = 1; i <= N; i++) {
        count[i] += count[i - 1];
    }
    
    // Process each query
    while (Q--) {
        int b, k;
        cin >> b >> k;
        
        // Binary search to find the k-th closest point
        int l = 1, r = 10e8;
        while (l < r) {
            int mid = (l + r + 1) / 2;
            // Count how many points are within distance mid
            int pos = lower_bound(sorted_a.begin(), sorted_a.end(), b + mid) - sorted_a.begin();
            int count_within_distance = count[pos];
            
            if (count_within_distance >= k) {
                l = mid; // mid is a valid distance, try for a smaller distance
            } else {
                r = mid - 1; // mid is too large, try a larger distance
            }
        }
        cout << r << endl;
    }
    
    return 0;
}