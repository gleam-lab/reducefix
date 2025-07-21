#include <bits/stdc++.h>
using namespace std;

int main() {
    ios::sync_with_stdio(false); cin.tie(nullptr);

    int n, k;
    cin >> n >> k;
    vector<long long> arr(n);
    for(int i = 0; i < n; ++i) cin >> arr[i];

    // Sort the array
    sort(arr.begin(), arr.end());

    // Calculate the difference between the maximum and minimum elements
    long long min_val = LLONG_MAX;
    long long max_val = LLONG_MIN;
    for(int i = 0; i <= n-k; ++i) {
        min_val = min(min_val, arr[i]);
        max_val = max(max_val, arr[i+k-1]);
    }

    // The result is the minimum difference found
    cout << max_val - min_val << '\n';

    return 0;
}