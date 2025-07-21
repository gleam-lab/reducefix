#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int main() {
    int n, k;
    cin >> n >> k;
    vector<long long> A(n);
    for (int i = 0; i < n; ++i) {
        cin >> A[i];
    }
    
    // Sort the array
    sort(A.begin(), A.end());
    
    // Binary search to find the best split point
    long long low = 0, high = n - 1;
    while (low < high) {
        int mid = (low + high) / 2;
        // Check if removing K elements from the start or end produces a smaller range
        long long minRange1 = (mid <= k) ? (A[mid] - A[0]) : (A[n - 1] - A[k - 1]);
        long long minRange2 = (n - 1 - mid <= k) ? (A[n - 1] - A[n - 1 - k]) : (A[mid] - A[0]);
        if (minRange1 <= minRange2) {
            high = mid;
        } else {
            low = mid + 1;
        }
    }
    
    // Output the minimum range found
    cout << (A[low] - A[low - k]) << endl;
    
    return 0;
}