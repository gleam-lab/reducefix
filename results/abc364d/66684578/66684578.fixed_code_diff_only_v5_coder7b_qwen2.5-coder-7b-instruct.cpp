#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
typedef pair<ll, int> pi;

const ll INF = 1e18;

vector<ll> sort_and_get_distances(const vector<ll>& a, const ll& b) {
    vector<ll> distances;
    for (const auto& x : a) {
        distances.push_back(abs(x - b));
    }
    sort(distances.begin(), distances.end());
    return distances;
}

int main() {
    ios_base::sync_with_stdio(false); cin.tie(0); cout.tie(0);

    int n, q;
    cin >> n >> q;
    vector<ll> a(n);
    for (int i = 0; i < n; ++i) {
        cin >> a[i];
    }

    vector<pi> queries(q);
    for (int i = 0; i < q; ++i) {
        cin >> queries[i].first >> queries[i].second;
    }

    // Precompute sorted distances for all points a_i to each b_j
    vector<vector<ll>> sorted_distances(q);
    for (int i = 0; i < q; ++i) {
        sorted_distances[i] = sort_and_get_distances(a, queries[i].first);
    }

    // Answer each query
    for (int i = 0; i < q; ++i) {
        cout << sorted_distances[i][queries[i].second - 1] << '\n';
    }

    return 0;
}