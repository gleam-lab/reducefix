#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    
    int n, k;
    cin >> n >> k;
    vector<int> a(n);
    
    for (int i = 0; i < n; i++) {
        cin >> a[i];
    }
    
    sort(a.begin(), a.end());
    
    int maxDifference = 0;
    // We remove pairs of elements to minimize the max of the remaining array
    // We can only remove a number if we remove its pair
    // We iterate through possible pairs to remove
    for (int i = 0; i < min(k, n / 2); i++) {
        // Remove the pair (a[i], a[n - i - 1]) if both elements are free for removal
        if (k - 2 * i > 0) {
            maxDifference = max(maxDifference, a[i] - a[n - i - 1]);
        }
    }
    
    // The answer is the maximum difference between the remaining elements
    cout << maxDifference << endl;
    
    return 0;
}