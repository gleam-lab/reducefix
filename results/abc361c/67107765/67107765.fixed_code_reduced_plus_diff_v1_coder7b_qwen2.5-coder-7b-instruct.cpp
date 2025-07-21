#include <bits/stdc++.h>
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

    // Sort the array
    sort(num.begin(), num.end());

    // Initialize the minimum difference to a large number
    long long min_diff = LLONG_MAX;

    // Use sliding window to find the minimum difference
    for (int i = 0; i <= n - k; i++) {
        long long diff = num[i + k - 1] - num[i];
        min_diff = min(min_diff, diff);
    }

    // Output the result
    cout << min_diff << endl;

    return 0;
}