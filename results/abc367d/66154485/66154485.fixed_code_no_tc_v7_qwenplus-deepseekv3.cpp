#include <bits/stdc++.h>
using namespace std;

int main() {
    int n, m;
    cin >> n >> m;
    vector<int> arr(n);
    for (int i = 0; i < n; i++) {
        cin >> arr[i];
    }

    // Handle circular array by concatenating it with itself
    vector<int> extended_arr(arr.begin(), arr.end());
    extended_arr.insert(extended_arr.end(), arr.begin(), arr.end());

    vector<int> prefix(2 * n + 1, 0);
    for (int i = 1; i <= 2 * n; i++) {
        prefix[i] = (prefix[i - 1] + extended_arr[i - 1]) % m;
    }

    unordered_map<int, int> freq;
    freq[0] = 1;
    long long ans = 0;

    for (int i = 1; i <= 2 * n; i++) {
        if (i > n) {
            int prev_prefix = prefix[i - n];
            freq[prev_prefix]--;
        }
        ans += freq[prefix[i]];
        freq[prefix[i]]++;
    }

    cout << ans - n << endl;  // Subtract n to exclude single-element subarrays counted in original array
    return 0;
}