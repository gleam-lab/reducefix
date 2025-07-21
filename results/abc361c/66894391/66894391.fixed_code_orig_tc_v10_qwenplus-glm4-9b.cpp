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

    vector<int> sorted_a(a);
    sort(sorted_a.begin(), sorted_a.end());

    int left = 0, right = n - 1;
    while (right - left > k) {
        if (k % 2 == 0) {
            int next_left = upper_bound(sorted_a.begin(), sorted_a.end(), sorted_a[left] + (sorted_a[right] - sorted_a[left]) / k) - sorted_a.begin();
            int next_right = upper_bound(sorted_a.begin(), sorted_a.end(), sorted_a[left] + (sorted_a[right] - sorted_a[left]) / k + 1) - sorted_a.begin();
            next_right = min(next_right, n - 1);

            if (next_right - next_left < right - left) {
                left = next_left;
                right = next_right;
            }
        } else {
            int mid_point = sorted_a[left] + (sorted_a[right] - sorted_a[left]) / 2;
            int count_left = upper_bound(sorted_a.begin(), sorted_a.end(), mid_point) - sorted_a.begin() - left;
            int count_right = min(right - upper_bound(sorted_a.begin(), sorted_a.end(), mid_point + 1), k - count_left);

            if (count_left + count_right <= k) {
                if (right - left > count_right) {
                    left = upper_bound(sorted_a.begin(), sorted_a.end(), mid_point) - sorted_a.begin();
                    right = upper_bound(sorted_a.begin(), sorted_a.end(), mid_point + 1) - sorted_a.begin() + count_left - count_right;
                }
            }
        }
    }

    cout << sorted_a[right] - sorted_a[left] << endl;

    return 0;
}