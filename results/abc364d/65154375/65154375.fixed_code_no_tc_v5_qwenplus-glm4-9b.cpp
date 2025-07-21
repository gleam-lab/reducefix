#include <bits/stdc++.h>
#define endl "\n"
using namespace std;

const int MAX_N = 200005;
int a[MAX_N], b[MAX_N], k[MAX_N];
int n, q;

struct Pair {
    int index;
    int value;
};

bool compare(const Pair& p1, const Pair& p2) {
    return p1.value < p2.value;
}

void solve() {
    int queries = 0;
    for (int i = 1; i <= q; ++i) {
        cin >> b[i] >> k[i];
        b[i]--;
        k[i]--;
        queries++;
    }

    // Calculate distances for each A_i for each B_j
    for (int i = 1; i <= n; ++i) {
        for (int j = 1; j <= queries; ++j) {
            a[i] += abs(b[j] - i);
        }
    }

    // Pair each A_i with its total distance and sort
    vector<Pair> dists;
    for (int i = 1; i <= n; ++i) {
        dists.emplace_back(Pair{i, a[i]});
    }
    sort(dists.begin(), dists.end(), compare);

    // For each query, find the k_j-th closest A_i to B_j
    for (int i = 1; i <= q; ++i) {
        cout << dists[k[i]].value << endl;
    }
}

int main() {
    cin >> n >> q;
    for (int i = 0; i < n; ++i) {
        cin >> a[i];
    }
    solve();
    return 0;
}