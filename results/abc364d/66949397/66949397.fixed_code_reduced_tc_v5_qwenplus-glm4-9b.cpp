#include <iostream>
#include <vector>
#include <algorithm>
#include <cmath>

using namespace std;

struct Query {
    long long b, k;
};

bool compare(const Query& q1, const Query& q2) {
    return q1.b < q2.b;
}

int main() {
    long long n, q;
    cin >> n >> q;
    vector<long long> a(n);
    vector<Query> queries(q);

    for (long long i = 0; i < n; ++i) {
        cin >> a[i];
    }

    for (long long i = 0; i < q; ++i) {
        cin >> queries[i].b >> queries[i].k;
    }

    sort(a.begin(), a.end());
    sort(queries.begin(), queries.end(), compare);

    vector<long long> distances(n);
    for (long long i = 0; i < n; ++i) {
        distances[i] = abs(a[i] - queries[i].b);
    }

    for (long long i = 0; i < q; ++i) {
        auto it = lower_bound(distances.begin(), distances.end(), queries[i].b, [&](const long long& d, const long long& b) {
            return d < b || (d == b && queries[i].k == 1);
        });

        long long result = (it - distances.begin()) + queries[i].k;
        if (result > n) {
            cout << LLONG_MAX << endl;
        } else {
            cout << abs(a[result - 1] - queries[i].b) << endl;
        }
    }

    return 0;
}