#include <bits/stdc++.h>
using namespace std;
using ll = long long;

// Function to get the least significant bit
int LSB(int n) {
    return n & (-n);
}

// Function to update the Fenwick Tree
void update(vector<ll>& tree, int index, int value) {
    while (index < tree.size()) {
        tree[index] += value;
        index += LSB(index);
    }
}

// Function to get the prefix sum up to a given index in the Fenwick Tree
ll prefix_sum(const vector<ll>& tree, int index) {
    ll sum = 0;
    while (index > 0) {
        sum += tree[index];
        index -= LSB(index);
    }
    return sum;
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int N;
    cin >> N;
    vector<int> X(N);
    vector<ll> P(N + 1, 0);
    
    // Read positions and accumulate villagers
    for (int i = 0; i < N; ++i) {
        cin >> X[i];
        cin >> P[i];
        P[i + 1] = P[i] + P[i];
    }

    // Find the maximum position to determine the size of the Fenwick Tree
    int max_pos = *max_element(begin(X), end(X));

    // Initialize Fenwick Tree with a size large enough to cover all positions
    vector<ll> fenwick_tree(max_pos + 2, 0);

    // Process each query
    int Q;
    cin >> Q;
    while (Q--) {
        int L, R;
        cin >> L >> R;

        // Update the Fenwick Tree for the range [L, R]
        update(fenwick_tree, L, P[R]);
        update(fenwick_tree, R + 1, -P[R]);

        // Get the result for the query
        ll result = prefix_sum(fenwick_tree, max_pos);
        cout << result << '\n';
    }

    return 0;
}