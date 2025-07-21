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
    
    int max_range = 0;
    
    // Calculate the maximum range by trying different numbers of removals from both ends
    for (int remove_left = 0; remove_left <= k; remove_left++) {
        for (int remove_right = 0; remove_right <= k; remove_right++) {
            if (remove_left + remove_right > k) continue; // Ensure total removals do not exceed k
            
            // Calculate the minimum and maximum of the remaining elements
            int min_val = (remove_left > 0) ? a[remove_left] : a[0];
            int max_val = (remove_right > 0) ? a[n - 1 - remove_right] : a[n - 1];
            
            // Update the maximum range found
            max_range = max(max_range, max_val - min_val);
        }
    }
    
    cout << max_range << endl;
    return 0;
}