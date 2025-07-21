#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int main() {
    int n, q;
    cin >> n >> q;
    vector<int> points(n);
    
    // Read the points A_i
    for (int i = 0; i < n; i++) {
        cin >> points[i];
    }
    
    while (q--) {
        int b, k;
        cin >> b >> k;
        k--; // Convert to 0-indexed
        
        // Find the k-th closest point to B_j
        // We have to find the k-th smallest index in points such that points[index] < b
        int index = lower_bound(points.begin(), points.end(), b) - points.begin();
        
        // The distance between the k-th closest point to B_j and B_j
        cout << abs(b - points[index]) << endl;
    }
    
    return 0;
}