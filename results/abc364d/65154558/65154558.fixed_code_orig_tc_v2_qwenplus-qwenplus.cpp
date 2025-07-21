#include <bits/stdc++.h>
using namespace std;

typedef long long ll;

const int OFFSET = 1e8; // Offset to handle negative indices

// Coordinate compression for efficient prefix sums
vector<ll> compressed;

struct Query {
    ll b;
    int k;
    int idx;
};

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int N, Q;
    cin >> N >> Q;

    vector<ll> A(N), B(Q);
    vector<int> K(Q);
    vector<Query> queries(Q);

    for (int i = 0; i < N; ++i) {
        cin >> A[i];
    }

    for (int i = 0; i < Q; ++i) {
        cin >> B[i] >> K[i];
        queries[i] = {B[i], K[i], i};
    }

    // Sort and deduplicate all possible coordinates
    set<ll> coord_set(A.begin(), A.end());
    for (ll b : B) {
        coord_set.insert(b);
        coord_set.insert(b - 2 * 1e8); // To cover lower range
        coord_set.insert(b + 2 * 1e8); // To cover upper range
    }

    compressed.assign(coord_set.begin(), coord_set.end());

    // Map values to compressed indices
    auto get_index = [&](ll x) {
        return lower_bound(compressed.begin(), compressed.end(), x) - compressed.begin();
    };

    // Prefix sum array of counts
    vector<int> cnt(compressed.size() + 2, 0);
    for (ll a : A) {
        cnt[get_index(a)]++;
    }

    // Build prefix sum
    vector<int> prefix(compressed.size() + 2, 0);
    for (size_t i = 1; i < prefix.size(); ++i) {
        prefix[i] = prefix[i - 1] + cnt[i - 1];
    }

    // Answer queries using binary search
    vector<pair<ll, int>> results(Q);

    for (const Query& q : queries) {
        ll b = q.b;
        int k = q.k;
        int l = 0, r = 2e8;
        int answer = 0;

        while (l <= r) {
            int mid = (l + r) / 2;
            int left = max(0LL, b - mid);
            int right = min(2e8, b + mid);

            // Find the count in the compressed coordinate system
            int left_idx = lower_bound(compressed.begin(), compressed.end(), left) - compressed.begin();
            int right_idx = upper_bound(compressed.begin(), compressed.end(), right) - compressed.begin();

            int count = prefix[right_idx] - prefix[left_idx];

            if (count >= k) {
                answer = mid;
                r = mid - 1;
            } else {
                l = mid + 1;
            }
        }

        results[q.idx] = {answer, q.k};
    }

    // Output results in original order
    for (const auto& res : results) {
        cout << res.first << "\n";
    }

    return 0;
}