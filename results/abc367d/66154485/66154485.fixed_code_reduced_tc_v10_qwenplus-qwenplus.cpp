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

    // Prefix sums
    vector<long long> prefix(n + 1, 0);
    for (int i = 0; i < n; ++i) {
        prefix[i + 1] = prefix[i] + arr[i];
    }

    // Count of remainders
    map<int, int> remainder_count;
    remainder_count[0] = 1; // For prefix sum 0

    long long result = 0;

    for (int i = 1; i <= n; ++i) {
        int rem = (prefix[i] % m + m) % m;
        result += remainder_count[rem];
        remainder_count[rem]++;
    }

    cout << result << "\n";
    return 0;
}