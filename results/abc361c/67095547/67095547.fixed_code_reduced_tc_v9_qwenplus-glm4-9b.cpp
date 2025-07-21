#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int main() {
    int n, k;
    cin >> n >> k;
    vector<long long> a(n);
    
    // Read the array
    for (int i = 0; i < n; ++i) {
        cin >> a[i];
    }
    
    // Sort the array to facilitate finding the minimum difference
    sort(a.begin(), a.end());
    
    long long minDiff = LLONG_MAX;
    
    // Try removing K elements starting from the left
    for (int left = 0; left <= n - k; ++left) {
        long long maxVal = a[left + k - 1];
        long long minVal = a[left];
        minDiff = min(minDiff, maxVal - minVal);
    }
    
    // Try removing K elements starting from the right
    for (int right = 0; right <= n - k; ++right) {
        long long maxVal = a[right + k - 1];
        long long minVal = a[right];
        minDiff = min(minDiff, maxVal - minVal);
    }
    
    // Try removing K elements from both ends
    if (k % 2 == 0) {
        for (int left = 0; left <= n - k / 2; ++left) {
            for (int right = left + k / 2; right <= n - k; ++right) {
                long long maxVal = max(a[left], a[right + k / 2 - 1]);
                long long minVal = min(a[left], a[right + k / 2 - 1]);
                minDiff = min(minDiff, maxVal - minVal);
            }
        }
    }
    
    cout << minDiff << endl;
    
    return 0;
}