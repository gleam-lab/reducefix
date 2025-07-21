#include<bits/stdc++.h>
using namespace std;
typedef long long ll;

int main() {
    int n, m;
    cin >> n >> m;
    vector<int> nums(n);
    for (int i = 0; i < n; ++i) {
        cin >> nums[i];
    }

    vector<ll> prefix(n + 1, 0);
    for (int i = 0; i < n; ++i) {
        prefix[i + 1] = prefix[i] + nums[i];
    }

    ll total_sum = prefix[n];
    ll count = 0;
    unordered_map<ll, ll> mod_counts;

    for (int i = 0; i <= n; ++i) {
        ll mod = (prefix[i] % m + m) % m;
        count += mod_counts[mod];
        mod_counts[mod]++;
    }

    mod_counts.clear();
    for (int i = 0; i <= n; ++i) {
        ll mod = ((prefix[i] - total_sum) % m + m) % m;
        count += mod_counts[mod];
        mod_counts[(prefix[i] % m + m) % m]++;
    }

    cout << count << endl;
    return 0;
}