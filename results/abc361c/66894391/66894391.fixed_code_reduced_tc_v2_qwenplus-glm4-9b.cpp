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
    
    sort(a.begin(), a.end());
    
    // Initialize the range with the maximum possible values.
    int currentMin = a[n - k - 1], currentMax = a[n - 1];
    int minRange = currentMax - currentMin;
    
    // Slide the window from the end to the beginning.
    for (int i = 0; i < k; i++) {
        currentMin = a[n - k - i - 1];
        currentMax = a[n - i - 1];
        minRange = min(minRange, currentMax - currentMin);
    }
    
    cout << minRange << endl;
    
    return 0;
}