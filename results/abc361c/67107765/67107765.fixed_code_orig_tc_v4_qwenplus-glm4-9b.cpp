#include <bits/stdc++.h>
using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int n, k;
    cin >> n >> k;
    vector<int> a(n);
    for (int i = 0; i < n; i++) {
        cin >> a[i];
    }
    sort(a.begin(), a.end());

    // Find the smallest element that is greater than or equal to a[k/2 - 1]
    int min_val_after_removal = upper_bound(a.begin(), a.begin() + k/2, a[k/2 - 1]) - a.begin();

    // Find the largest element that is less than or equal to a[n - k/2]
    int max_val_after_removal = lower_bound(a.begin() + n - k/2, a.end(), a[n - k/2]) - a.begin();

    // Calculate and print the result
    cout << a[max_val_after_removal] - a[min_val_after_removal] << endl;
    return 0;
}