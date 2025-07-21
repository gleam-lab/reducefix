#include<bits/stdc++.h>
#include<array>
#define endl "\n"
using namespace std;

const int N = 100000; // Adjust the size as necessary
int A[N];

struct Query {
    int b, k;
    int index;
};

bool compare(const Query& a, const Query& b) {
    return a.k < b.k;
}

void solve() {
    int n, q; cin >> n >> q;
    for (int i = 0; i < n; ++i) {
        cin >> A[i];
    }

    // Sort the array A
    sort(A, A + n);

    vector<Query> queries;
    for (int i = 0; i < q; ++i) {
        int b, k; cin >> b >> k;
        queries.push_back({b, k, i});
    }

    // Sort queries by k
    sort(queries.begin(), queries.end(), compare);

    vector<int> results(q);
    int j = 0; // Pointer for A
    for (const auto& q : queries) {
        while (j < n && A[j] < q.b) {
            j++;
        }
        int count = 0;
        for (int i = j; i < n && A[i] <= q.b + q.k; ++i) {
            count++;
            if (count == q.k) {
                results[q.index] = abs(q.b - A[i]);
                break;
            }
        }
    }

    for (int res : results) {
        cout << res << endl;
    }
}

int main() {
    solve();
    return 0;
}