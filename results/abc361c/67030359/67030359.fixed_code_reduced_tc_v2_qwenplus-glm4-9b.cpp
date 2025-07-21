#include <bits/stdc++.h>

using namespace std;

#define ll long long

ll minRangeDifference(vector<ll>& v, int remove_count) {
    int size = v.size();
    if (size - remove_count < 2) return 0; // Not enough elements to form a range

    vector<ll> prefix_min(size, 0);
    vector<ll> suffix_min(size, 0);
    vector<ll> prefix_max(size, 0);
    vector<ll> suffix_max(size, 0);

    prefix_min[0] = v[0];
    prefix_max[0] = v[0];
    for (int i = 1; i < size; ++i) {
        prefix_min[i] = min(prefix_min[i - 1], v[i]);
        prefix_max[i] = max(prefix_max[i - 1], v[i]);
    }

    suffix_min[size - 1] = v.back();
    suffix_max[size - 1] = v.back();
    for (int i = size - 2; i >= 0; --i) {
        suffix_min[i] = min(suffix_min[i + 1], v[i]);
        suffix_max[i] = max(suffix_max[i + 1], v[i]);
    }

    ll min_diff = LLONG_MAX;

    // Check for all possible ranges
    for (int i = 0; i <= size - remove_count; ++i) {
        ll max_val = 0;
        ll min_val = LLONG_MAX;
        for (int j = i; j < i + remove_count; ++j) {
            min_val = min(min_val, prefix_min[j], suffix_min[j]);
            max_val = max(max_val, prefix_max[j], suffix_max[j]);
        }
        min_diff = min(min_diff, max_val - min_val);
    }

    return min_diff;
}

int main() {
    int N, K;
    cin >> N >> K;
    vector<ll> A(N);
    for (int i = 0; i < N; ++i) {
        cin >> A[i];
    }

    ll answer = minRangeDifference(A, K);
    cout << answer << endl;

    return 0;
}