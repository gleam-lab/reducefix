#include <iostream>
#include<algorithm>
#include<queue>
#include<map>
#include<vector>
#include<cstring>
using namespace std;

typedef long long ll;

struct Point {
    ll x, k;
};

bool compare(const Point &a, const Point &b) {
    return a.k < b.k;
}

vector<ll> solve(vector<ll> &pointsA, vector<Point> &queries) {
    sort(pointsA.begin(), pointsA.end());
    vector<ll> results(queries.size());

    for (size_t i = 0; i < queries.size(); ++i) {
        ll k = queries[i].k;
        auto it = upper_bound(pointsA.begin(), pointsA.end(), queries[i].x);

        // If k > number of points, return infinity
        if (it - pointsA.begin() < k) {
            results[i] = INT_MAX;
        } else {
            // The k-th closest point will be at position k-1 after sorting
            results[i] = abs(pointsA[it - pointsA.begin() - k] - queries[i].x);
        }
    }

    return results;
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int n, q;
    cin >> n >> q;

    vector<ll> pointsA(n);
    for (int i = 0; i < n; ++i) {
        cin >> pointsA[i];
    }

    vector<Point> queries(q);
    for (int i = 0; i < q; ++i) {
        cin >> queries[i].x >> queries[i].k;
        --queries[i].k; // Adjusting k to zero-based index
    }

    vector<ll> results = solve(pointsA, queries);

    for (ll result : results) {
        cout << result << endl;
    }

    return 0;
}