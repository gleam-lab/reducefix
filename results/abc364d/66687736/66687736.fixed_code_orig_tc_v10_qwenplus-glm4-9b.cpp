#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int main() {
    int n, q;
    cin >> n >> q;
    
    vector<int> a(n), distances(n);
    
    // Read and store points in array `a`
    for (int i = 0; i < n; ++i) {
        cin >> a[i];
    }
    
    // Prepare distance array
    for (int i = 0; i < n; ++i) {
        distances[i] = a[i];
    }
    
    // Sort the distances
    sort(distances.begin(), distances.end());
    
    // Process each query
    for (int q_i = 0; q_i < q; ++q_i) {
        int b, k;
        cin >> b >> k;
        
        // Binary search for the k-th closest point
        int low = 0, high = n - 1;
        int kth_closest_index;
        
        while (low <= high) {
            int mid = (low + high) / 2;
            int distance = abs(distances[mid] - b);
            
            if (mid == 0) {
                kth_closest_index = mid;
                break;
            } else if (distance == abs(distances[mid - 1] - b)) {
                kth_closest_index = mid - 1;
                break;
            } else if (distance < abs(distances[mid - 1] - b)) {
                high = mid - 1;
            } else {
                kth_closest_index = mid;
                break;
            }
        }
        
        // Output the distance of the k-th closest point from B
        cout << abs(distances[kth_closest_index] - b) << endl;
    }
    
    return 0;
}