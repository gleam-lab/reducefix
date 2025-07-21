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
    
    // Sort the vector to easily find the range of elements to remove
    sort(a.begin(), a.end());
    
    // The maximum possible difference we can get is between the two largest or two smallest elements
    // after removing K elements.
    // Case 1: Remove K largest elements
    int max_diff_1 = a[n - k - 1] - a[0];
    
    // Case 2: Remove K smallest elements
    int max_diff_2 = a[n - 1] - a[k];
    
    // The minimum possible value of the maximum difference is the minimum of these two cases
    cout << min(max_diff_1, max_diff_2);
    return 0;
}