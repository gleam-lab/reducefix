#include <bits/stdc++.h>
using namespace std;

typedef long long ll;

const int MAXN = 1e5 + 5;

// A structure to represent queries
struct Query {
    ll b;
    int k;
    int idx;
};

vector<ll> a; // Positions of A points
ll results[MAXN]; // Store results temporarily

// Function to process all queries for a particular B_j
void solveQueries(const vector<Query>& queries, const vector<ll>& sorted_a) {
    for (const auto& q : queries) {
        ll b = q.b;
        int k = q.k;

        // Binary search for the k-th smallest distance
        ll left = 0, right = 2e8;
        while (left < right) {
            ll mid = (left + right) / 2;

            // Count how many elements in sorted_a are within [b-mid, b+mid]
            ll lower = b - mid;
            ll upper = b + mid;

            auto l = lower_bound(sorted_a.begin(), sorted_a.end(), lower);
            auto r = upper_bound(sorted_a.begin(), sorted_a.end(), upper);
            int count = r - l;

            if (count >= k) {
                right = mid;
            } else {
                left = mid + 1;
            }
        }

        results[q.idx] = left;
    }
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);

    int N, Q;
    cin >> N >> Q;

    a.resize(N);
    for (int i = 0; i < N; ++i) {
        cin >> a[i];
    }

    sort(a.begin(), a.end());

    vector<Query> queries[4];
    // Handle multiple binary searches by dividing queries into groups
    // based on the value of k. This helps with cache efficiency.
    for (int i = 0; i < Q; ++i) {
        ll b;
        int k;
        cin >> b >> k;
        // Divide queries based on k
        int group = min(3, (int)log2(k));
        queries[group].push_back({b, k, i});
    }

    // Solve queries grouped by k
    for (int g = 0; g < 4; ++g) {
        if (!queries[g].empty()) {
            solveQueries(queries[g], a);
        }
    }

    // Output results in original order
    for (int i = 0; i < Q; ++i) {
        cout << results[i] << "\n";
    }

    return 0;
}