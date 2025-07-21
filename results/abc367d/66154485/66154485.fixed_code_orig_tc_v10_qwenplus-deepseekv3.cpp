#include <bits/stdc++.h>
using namespace std;

int main() {
    int n, m;
    cin >> n >> m;
    vector<int> arr(n);
    for (int i = 0; i < n; ++i) {
        cin >> arr[i];
    }

    long long ans = 0;
    vector<int> prefix_mod(n + 1, 0);
    unordered_map<int, int> mod_count;
    mod_count[0] = 1;

    for (int i = 1; i <= n; ++i) {
        prefix_mod[i] = (prefix_mod[i - 1] + arr[i - 1]) % m;
        if (prefix_mod[i] < 0) {
            prefix_mod[i] += m;
        }
        ans += mod_count[prefix_mod[i]];
        mod_count[prefix_mod[i]]++;
    }

    cout << ans << endl;
    return 0;
}