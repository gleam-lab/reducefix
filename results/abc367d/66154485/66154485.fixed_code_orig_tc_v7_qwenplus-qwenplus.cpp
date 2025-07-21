#include <bits/stdc++.h>
using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int n, m;
    cin >> n >> m;
    vector<int> arr(n);
    for (int i = 0; i < n; ++i) {
        cin >> arr[i];
    }

    // Prefix sum mod m
    vector<int> prefix_mod(n + 1, 0);
    for (int i = 0; i < n; ++i) {
        prefix_mod[i + 1] = (prefix_mod[i] + arr[i]) % m;
    }

    // To count frequency of each mod value
    map<int, int> freq;
    freq[0] = 1; // initial 0 to handle subarrays starting from index 0

    long long ans = 0;
    for (int i = 1; i <= n; ++i) {
        // For circular array, we consider all rotations:
        // We subtract the contribution of prefix_mod[i - 1] from all previous prefix sums
        // This is equivalent to rotating the array such that current index becomes start
        // So instead of (prefix[j] - prefix[i]) % m == 0, we want (prefix_mod[j] - prefix_mod[i - 1]) % m == 0
        // Which simplifies to prefix_mod[j] % m == prefix_mod[i - 1] % m
        // So we keep a running frequency count and subtract before updating answer
        if (freq[prefix_mod[i - 1]] > 0)
            ans += freq[prefix_mod[i - 1]] - 1;
        freq[prefix_mod[i]]++;
    }

    cout << ans << endl;
    return 0;
}