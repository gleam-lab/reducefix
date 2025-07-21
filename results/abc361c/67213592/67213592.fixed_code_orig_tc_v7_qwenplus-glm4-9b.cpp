#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int main() {
    int n, k;
    cin >> n >> k;
    vector<int> v(n);
    for (int i = 0; i < n; ++i) {
        cin >> v[i];
    }
    
    // Sort the array first
    sort(v.begin(), v.end());
    
    // This will keep track of the smallest maximum minus the minimum difference
    int min_diff = INT_MAX;

    // We will consider the case where we remove elements from either side of the array
    for (int i = 0; i <= n - k; ++i) {
        // Calculate the difference for the current window
        int max_val = v[n - k + i];
        int min_val = v[i];
        int diff = max_val - min_val;
        
        // Update the minimum difference
        min_diff = min(min_diff, diff);
    }

    cout << min_diff << endl;

    return 0;
}