#include <iostream>
#include <vector>
#include <algorithm>
#include <cmath>
using namespace std;

const int N = 1e5 + 9;
vector<int> a(N), b(N);

int main() {
    int n, q;
    cin >> n >> q;
    
    // Reading points A and B
    for (int i = 0; i < n; ++i) {
        cin >> a[i];
    }
    for (int i = 0; i < q; ++i) {
        cin >> b[i];
    }
    
    vector<int> results(q, 0); // To store the results for each query
    
    // Sorting a for binary search
    sort(a.begin(), a.end());
    
    // For each point B, find the k-th closest A
    for (int i = 0; i < q; ++i) {
        int x = b[i]; // Point B
        int k = 1; // k-th closest
        
        // Binary search for the k-th closest point
        int left = 0, right = n - 1;
        while (left < right) {
            int mid = left + (right - left + 1) / 2;
            if (a[mid] < x) {
                left = mid;
            } else {
                right = mid - 1;
            }
        }
        
        if (a[left] != x) {
            results[i] = -1; // No k-th closest point found
        } else {
            // Found the k-th closest point, calculate the distance
            results[i] = abs(a[left] - x);
        }
    }
    
    // Output the results
    for (int res : results) {
        cout << res << endl;
    }
    
    return 0;
}