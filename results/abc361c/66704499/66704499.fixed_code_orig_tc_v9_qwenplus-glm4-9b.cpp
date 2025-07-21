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

    // Calculate the minimum possible value of B - max(B)
    // Case 1: Remove the K smallest elements
    int min_value_after_removal = a[k]; // Minimum value of the new sequence after removing K smallest elements
    int max_value_after_removal = a[n - 1]; // Maximum value of the new sequence after removing K smallest elements
    int min_max_diff_case1 = max_value_after_removal - min_value_after_removal;

    // Case 2: Remove the K largest elements
    min_value_after_removal = a[0]; // Minimum value of the new sequence after removing K largest elements
    max_value_after_removal = a[n - k - 1]; // Maximum value of the new sequence after removing K largest elements
    int min_max_diff_case2 = max_value_after_removal - min_value_after_removal;

    // The answer is the minimum of the two cases
    cout << min(min_max_diff_case1, min_max_diff_case2) << endl;

    return 0;
}