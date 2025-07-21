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
    vector<int> prefix(n + 1, 0);
    for (int i = 0; i < n; ++i) {
        prefix[i + 1] = (prefix[i] + arr[i]) % m;
    }

    map<int, int> freq;
    long long result = 0;

    // We'll use the circular nature of the array by considering all prefix sums
    for (int i = 0; i < n; ++i) {
        // Count how many times this mod value has occurred before
        result += freq[prefix[i]];
        // Now update the frequency map with current prefix[i]
        freq[prefix[i]]++;
    }

    cout << result << endl;
    return 0;
}