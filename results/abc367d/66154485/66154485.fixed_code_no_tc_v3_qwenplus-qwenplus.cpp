#include <bits/stdc++.h>
using namespace std;

int main() {
    int n, m;
    cin >> n >> m;
    vector<int> arr(n);
    for (int i = 0; i < n; i++) {
        cin >> arr[i];
    }

    // Prefix sum mod array
    vector<int> prefix_mod(n + 1, 0);
    for (int i = 0; i < n; i++) {
        prefix_mod[i + 1] = (prefix_mod[i] + arr[i]) % m;
    }

    // Use a frequency map to count occurrences of each mod value
    unordered_map<int, int> freq;
    long long ans = 0;

    for (int i = 0; i <= n; i++) {
        // For each prefix_mod[i], add the number of previous prefixes with the same mod
        // These form subarrays whose sum mod m == 0
        ans += freq[prefix_mod[i]];
        freq[prefix_mod[i]]++;
    }

    cout << ans << endl;
    return 0;
}