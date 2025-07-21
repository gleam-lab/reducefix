#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int main() {
    int n, k;
    cin >> n >> k;
    vector<int> a(n);
    for (int i = 0; i < n; ++i) cin >> a[i];

    // Sort the array to make it easier to find the largest gaps
    sort(a.begin(), a.end());

    // Create an array of differences
    vector<int> gaps(n - 1);
    for (int i = 1; i < n; ++i) {
        gaps[i - 1] = a[i] - a[i - 1];
    }

    // Sort the gaps in descending order
    sort(gaps.begin(), gaps.end(), greater<int>());

    // Remove the K largest gaps
    for (int i = 0; i < k; ++i) {
        a.erase(remove_if(a.begin(), a.end(),
                          [gaps, i](int x) { return x == gaps[i]; }),
                a.end());
    }

    // Now, the new array 'a' is left with n-k elements
    // Find the minimum and maximum of these elements
    int min_val = *min_element(a.begin(), a.end());
    int max_val = *max_element(a.begin(), a.end());

    // Output the result
    cout << max_val - min_val << endl;

    return 0;
}