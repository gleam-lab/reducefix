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
    
    // Calculate the range if we remove k elements from the start
    int remove_from_start = a[k - 1] - a[0];
    
    // Calculate the range if we remove k elements from the end
    int remove_from_end = a[n - 1] - a[n - k];
    
    // The answer is the minimum of the two ranges
    cout << min(remove_from_start, remove_from_end) << endl;
    
    return 0;
}