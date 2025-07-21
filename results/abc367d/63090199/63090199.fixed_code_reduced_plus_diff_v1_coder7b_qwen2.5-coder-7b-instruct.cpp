#include <bits/stdc++.h>
using namespace std;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int n, m;
    cin >> n >> m;
    vector<int> nums(n);
    for (int i = 0; i < n; ++i) {
        cin >> nums[i];
    }

    vector<int> prefixsum(n + 1, 0);
    for (int i = 0; i < n; ++i) {
        prefixsum[i + 1] = prefixsum[i] + nums[i];
    }

    long long count = 0;
    for (int s = 1; s <= n; ++s) {
        for (int t = s + 1; t <= n; ++t) {
            int step = prefixsum[t] - prefixsum[s - 1];
            if (step % m == 0) {
                count += t - s;
            }
        }
    }

    cout << count << endl;
    return 0;
}