#include <iostream>
#include <vector>
#include <map>
#include <algorithm>

using namespace std;

#define ll long long

int main() {
    ll n, q;
    cin >> n >> q;
    vector<ll> a(n);
    map<ll, ll> freq;
    ll min_a = LLONG_MAX, max_a = LLONG_MIN;

    // Read and store all coordinates of A
    for (ll i = 0; i < n; ++i) {
        cin >> a[i];
        freq[a[i]]++;
        min_a = min(min_a, a[i]);
        max_a = max(max_a, a[i]);
    }

    // Convert frequency map to cumulative frequencies
    map<ll, ll> cum_freq;
    for (auto&[key, value] : freq) {
        if (!cum_freq.empty()) {
            cum_freq[key] = cum_freq[cum_freq.rbegin()->first] + value;
        } else {
            cum_freq[key] = value;
        }
    }

    // Read and process each query
    for (ll j = 0; j < q; ++j) {
        ll b, k;
        cin >> b >> k;
        k--; // Convert to 0-based index
        ll left = LLLONG_MAX, right = LLLONG_MIN;

        // Find the range of possible a coordinates
        for (auto&[key, value] : cum_freq) {
            if (value > k) {
                right = min(right, key);
            } else if (value == k) {
                left = max(left, key);
            }
        }

        // If left and right are the same, it means the k-th closest point is at the same position as b
        if (left == right) {
            cout << (right - b) * (right - b) << endl;
        } else {
            // Binary search to find the k-th closest point
            while (right - left > 1) {
                ll mid = left + (right - left) / 2;
                if (cum_freq[mid] > k) {
                    right = mid;
                } else {
                    left = mid;
                }
            }
            ll closest = left;
            cout << (closest - b) * (closest - b) << endl;
        }
    }

    return 0;
}