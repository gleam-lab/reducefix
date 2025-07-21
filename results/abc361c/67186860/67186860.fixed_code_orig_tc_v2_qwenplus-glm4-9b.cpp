#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int main() {
    int n, k;
    cin >> n >> k;
    vector<int> a(n);
    
    for (int i = 0; i < n; i++) {
        cin >> a[i];
    }

    // Sort the array A
    sort(a.begin(), a.end());
    
    int ans = INT_MAX;

    // Try removing K elements from different parts of the sorted array
    for (int i = 0; i <= n - k; i++) { // i is the left end of the removed elements
        int j = i + k - 1; // j is the right end of the removed elements
        int maxB = a[j]; // The maximum value in the remaining elements
        int minB = a[i + 1 - k]; // The minimum value in the remaining elements
        
        // Update the answer if the current gap is smaller
        ans = min(ans, maxB - minB);
    }

    cout << ans << endl;
    return 0;
}