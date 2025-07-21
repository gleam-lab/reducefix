#include <iostream>
#include <algorithm>
#include <vector>
#include <cmath>
using namespace std;

const int N = 2e5 + 9;
int n, q;
vector<long long> a;

struct Query {
    long long b, k;
    int index;
};

vector<Query> queries;

bool compare(const Query &x, const Query &y) {
    return x.b < y.b;
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);

    cin >> n >> q;

    a.resize(n);
    for (int i = 0; i < n; ++i) {
        cin >> a[i];
    }

    queries.resize(q);
    for (int i = 0; i < q; ++i) {
        cin >> queries[i].b >> queries[i].k;
        queries[i].index = i;
    }

    sort(queries.begin(), queries.end(), compare);

    vector<int> b_index(n);
    for (int i = 0, j = 0; i < q; ++i) {
        while (j < n && a[j] < queries[i].b) {
            b_index[j++] = i;
        }
    }

    for (int i = 0; i < q; ++i) {
        int idx = queries[i].index;
        long long b = queries[i].b, k = queries[i].k;
        int count = 0;

        for (int j = b_index[i]; j < n && count < k; ++j) {
            if (k == 1 || a[j] > queries[idx - 1].b || a[j] < queries[idx + 1].b) {
                queries[idx].k = abs(a[j] - b); // Calculate the distance
                break;
            }
            ++count;
        }

        if (queries[idx].k == 0) {
            queries[idx].k = -1; // If no such point exists, set to -1
        }
    }

    for (const auto &query : queries) {
        if (query.k == -1) {
            cout << "No such point exists" << endl;
        } else {
            cout << query.k << endl;
        }
    }

    return 0;
}