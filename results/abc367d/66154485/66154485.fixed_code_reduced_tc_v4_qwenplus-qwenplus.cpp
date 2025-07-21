#include <bits/stdc++.h>
using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int n, m;
    cin >> n >> m;

    vector<int> arr(2 * n);
    for (int i = 0; i < n; ++i) {
        cin >> arr[i];
        arr[i + n] = arr[i]; // duplicate for circular wrap-around
    }

    long long ans = 0;
    vector<long long> freq(m, 0);
    long long prefix_sum = 0;

    for (int i = 0; i < 2 * n; ++i) {
        prefix_sum = (prefix_sum + arr[i]) % m;
        if (i >= n) {
            // Remove contribution of the element that falls out of the sliding window of size n
            int old_rem = (prefix_sum - arr[i - n] + m) % m;
            freq[old_rem]--;
        }
        ans += freq[prefix_sum]++;
    }

    cout << ans << "\n";
    return 0;
}