#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int main() {
    int n, k;
    cin >> n >> k;
    vector<int> a(n);
    
    // Input the array elements
    for (int i = 0; i < n; ++i) {
        cin >> a[i];
    }
    
    // Sort the array
    sort(a.begin(), a.end());
    
    // Calculate the maximum difference after removing k elements
    // by considering two cases: removing the smallest k elements or the largest k elements
    int min_diff = a[n - 1 - k] - a[k]; // Case 1: Remove the smallest k elements
    min_diff = min(min_diff, a[n - 2 - k] - a[k + 1]); // Case 2: Remove the largest k elements
    
    cout << min_diff << endl;
    return 0;
}