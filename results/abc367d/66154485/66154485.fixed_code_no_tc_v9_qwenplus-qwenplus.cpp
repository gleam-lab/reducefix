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

    // To count occurrences of each mod value
    vector<int> mod_count(m, 0);
    int ans = 0;

    for (int i = 0; i <= n; i++) {
        // Count how many times this mod has occurred before
        ans += mod_count[prefix_mod[i]];
        // Increment the count for current mod
        mod_count[prefix_mod[i]]++;
    }

    cout << ans << endl;
    return 0;
}