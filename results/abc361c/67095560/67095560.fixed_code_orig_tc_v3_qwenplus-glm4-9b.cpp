#include <iostream>
#include <vector>
#include <algorithm>
#include <climits>

using namespace std;

int main() {
    int n, k;
    cin >> n >> k;
    vector<int> a(n);
    
    for (int i = 0; i < n; ++i) {
        cin >> a[i];
    }
    
    sort(a.begin(), a.end());
    
    int i = 0, j = n - 1;
    int removed_elements = 0;
    int ans = INT_MAX;
    
    // Find the first point where we can remove k elements such that the difference
    // between the max and min of the remaining elements is minimized.
    while (i <= j && removed_elements < k) {
        if (j - i + 1 > k - removed_elements) {
            j--;
        } else {
            int new_diff = a[j] - a[i];
            ans = min(ans, new_diff);
            i++;
        }
        removed_elements++;
    }
    
    cout << ans << endl;
    
    return 0;
}