#include <bits/stdc++.h>
using namespace std;

#define ll long long
#define vi vector<int>

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int n, q;
    cin >> n >> q;

    vi A(n);
    for (int i = 0; i < n; ++i) {
        cin >> A[i];
    }

    sort(A.begin(), A.end());

    // Build prefix map using upper_bound/lower_bound
    map<int, int> prefixCount;
    for (int i = 0; i < n; ++i) {
        prefixCount[A[i]]++;
    }

    // Rebuild map with cumulative counts
    map<int, int> mp;
    int count = 0;
    for (auto it = prefixCount.begin(); it != prefixCount.end(); ++it) {
        count += it->second;
        mp[it->first] = count;
    }
    mp[-200000000] = 0; // lower bound
    mp[200000000] = n;  // upper bound

    auto get = [&](int x) {
        if (mp.find(x) != mp.end()) return mp[x];
        auto it = mp.lower_bound(x);
        if (it == mp.begin()) return 0;
        --it;
        return it->second;
    };

    while (q--) {
        int b, k;
        cin >> b >> k;

        int low = 0, high = 200000000;
        int ans = high;

        while (low <= high) {
            int mid = (low + high) / 2;
            int left = b - mid;
            int right = b + mid;

            int cnt = get(right) - get(left - 1);
            if (cnt >= k) {
                ans = mid;
                high = mid - 1;
            } else {
                low = mid + 1;
            }
        }

        cout << ans << "\n";
    }

    return 0;
}