#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int main() {
    int n, k;
    cin >> n >> k;
    vector<int> a(n);
    for (int i = 0; i < n; ++i) cin >> a[i];

    // Remove the largest and the smallest elements first
    sort(a.begin(), a.end());
    int min_val = a[0];
    int max_val = a[n - 1];
    a.erase(remove(a.begin(), a.end(), min_val), a.end());
    a.erase(remove(a.begin(), a.end(), max_val), a.end());

    // Now we need to remove k-2 elements to minimize a[max] - a[min] as much as possible
    if (k > 2) {
        // Sort the remaining elements
        sort(a.begin(), a.end());

        // We can remove the largest and smallest elements from the remaining sorted array
        // to minimize the range after every two removals
        int min_diff = a.back() - a.front();

        // Find the smallest difference by trying to remove one element that's not the largest or smallest
        for (size_t i = 1; i < a.size() - 1; ++i) {
            int new_min = a[i - 1];
            int new_max = a[a.size() - 2 - i];  // We're removing the i-th and the (n-2-i)-th largest elements
            min_diff = min(min_diff, new_max - new_min);
        }
        cout << min_diff << endl;
    } else {
        // If k <= 2, we can only remove the largest and smallest elements
        cout << max_val - min_val << endl;
    }

    return 0;
}