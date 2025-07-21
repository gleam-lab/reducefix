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
    
    // If we remove k elements, we're left with n-k elements, so we need to find the minimum difference
    // between the maximum and minimum of these n-k elements.
    sort(a.begin(), a.end()); // Sort the array to easily identify the K largest elements
    
    // The largest element after removing k elements will be a[n-k-1]
    // The smallest element after removing k elements will be a[k]
    int min_diff = a[n-k-1] - a[k];
    
    cout << min_diff << endl;
    
    return 0;
}