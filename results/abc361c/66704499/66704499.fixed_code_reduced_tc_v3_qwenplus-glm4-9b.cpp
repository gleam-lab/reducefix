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
    
    // Sort the array
    sort(a.begin(), a.end());
    
    // Calculate prefix sums
    vector<long long> prefix(n + 1, 0);
    for (int i = 0; i < n; ++i) {
        prefix[i + 1] = prefix[i] + a[i];
    }
    
    long long minRange = LLONG_MAX;
    
    // Iterate over possible "left" elements
    for (int left = 0; left < n - k; ++left) {
        // Binary search for optimal "right" element
        int low = left + k, high = n - 1;
        while (low < high) {
            int mid = (low + high + 1) / 2;
            long long sumLeft = prefix[left + 1] - prefix[mid + 1];
            long long sumRight = prefix[n] - prefix[mid + 1];
            
            long long maxVal = max(a[mid], sumRight / (n - k - mid));
            long long minVal = min(a[mid], sumLeft / k);
            
            if (maxVal - minVal < minRange) {
                minRange = maxVal - minVal;
            }
            
            if (maxVal > minVal) {
                low = mid + 1;
            } else {
                high = mid - 1;
            }
        }
    }
    
    cout << minRange << endl;
    
    return 0;
}