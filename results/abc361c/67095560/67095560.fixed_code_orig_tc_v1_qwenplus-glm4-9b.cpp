#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int main() {
    int n, k;
    cin >> n >> k;
    vector<int> a(n);
    for (int i = 0; i < n; ++i) {
        cin >> a[i];
    }
    
    sort(a.begin(), a.end());  // Sort the array
    
    int minDifference = INT_MAX;
    
    // Use a sliding window of size n-k
    for (int i = 0; i <= n - k; ++i) {
        int maxB = a[i + k - 1];  // Last element in the current window
        int minB = a[i];          // First element in the current window
        int diff = maxB - minB;
        minDifference = min(minDifference, diff);
    }
    
    cout << minDifference << endl;
    
    return 0;
}