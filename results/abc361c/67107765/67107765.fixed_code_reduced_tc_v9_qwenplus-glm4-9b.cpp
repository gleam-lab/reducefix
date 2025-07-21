#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    int n, k;
    cin >> n >> k;
    vector<int> num(n);
    for (int i = 0; i < n; i++) {
        cin >> num[i];
    }
    sort(num.begin(), num.end());

    int left = 0, right = n - 1;
    while (right - left + 1 > k) {
        // Check the difference between the two ends of the remaining elements after removing k elements
        int diff_left = num[right] - num[left];
        int diff_right = num[right - 1] - num[left + 1];

        if (diff_left <= diff_right) {
            left++;  // Remove from the left side
        } else {
            right--; // Remove from the right side
        }
    }

    // The remaining elements are from left+1 to right
    int min_val = num[left + 1];
    int max_val = num[right];
    cout << max_val - min_val << endl;

    return 0;
}