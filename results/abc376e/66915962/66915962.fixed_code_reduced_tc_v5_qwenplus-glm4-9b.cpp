#include <iostream>
#include <vector>
#include <algorithm>
#include <set>
using namespace std;
using ll = long long;

int main() {
    int t;
    cin >> t;
    while (t--) {
        int n, k;
        cin >> n >> k;
        vector<ll> a(n), b(n);
        for (int i = 0; i < n; ++i) {
            cin >> a[i] >> b[i];
        }

        vector<pair<ll, ll>> pairs(n);
        for (int i = 0; i < n; ++i) {
            pairs[i] = {b[i], a[i]};
        }

        // Sort pairs by the second element (b[i]) descending
        sort(pairs.begin(), pairs.end(), greater<pair<ll, ll>>());

        ll totalB = 0;
        set<ll> usedB;
        for (int i = 0; i < k; ++i) {
            if (usedB.count(pairs[i].second) == 0) {
                usedB.insert(pairs[i].second);
                totalB += pairs[i].first;
            }
        }

        ll min_value = LLONG_MAX;
        for (int i = k; i < n; ++i) {
            if (usedB.count(pairs[i].second) == 0) {
                usedB.insert(pairs[i].second);
                totalB += pairs[i].first;
                min_value = min(min_value, pairs[i].second * totalB);
                totalB -= (usedB.find(pairs[i - k].second) != usedB.end() ? pairs[i - k].first : 0);
                usedB.erase(pairs[i - k].second);
            }
        }

        cout << min_value << '\n';
    }
    return 0;
}