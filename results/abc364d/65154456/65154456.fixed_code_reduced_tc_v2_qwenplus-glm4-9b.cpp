#include <bits/stdc++.h>
using namespace std;

const int N = 1e5 + 10;
int a[N];

struct Query {
    int b, k;
    int index;
};

bool compare(const Query& q1, const Query& q2) {
    return a[q1.b] < a[q2.b];
}

void solve() {
    int n, q;
    cin >> n >> q;
    for (int i = 0; i < n; ++i) {
        cin >> a[i];
    }

    vector<Query> queries;
    for (int i = 0; i < q; ++i) {
        int b, k;
        cin >> b >> k;
        queries.emplace_back(b, k, i);
    }

    // Sort queries by the position of the query point b
    sort(queries.begin(), queries.end(), [](const Query& q1, const Query& q2) {
        return q1.b < q2.b;
    });

    // Create a mapping of original queries to sorted queries
    vector<int> order(q);
    iota(order.begin(), order.end(), 0);

    // Sort by distance from b to a
    sort(queries.begin(), queries.end(), compare);

    // Store sorted distances in an array
    vector<long long> sorted_distances;
    for (int i = 0; i < n; ++i) {
        sorted_distances.push_back(abs(a[queries[i].b] - a[i]));
    }

    // Answer each query
    for (const auto& query : queries) {
        int k = query.k - 1; // Convert to 0-based index
        if (k >= 0 && k < sorted_distances.size()) {
            cout << sorted_distances[k] << endl;
        } else {
            cout << 0 << endl; // In case k is out of bounds, which should not happen
        }
    }
}

int main() {
    solve();
    return 0;
}