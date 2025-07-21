#include<iostream>
#include<algorithm>
using namespace std;

#define ll long long
const int MAXN = 2e5 + 9, INF = 1e9;

struct Node {
    int val, idx;
};

// Custom comparator to sort nodes based on their values
bool cmp(Node &a, Node &b) {
    return a.val > b.val;
}

void solve(int N, int K, vector<ll>& A, vector<ll>& B) {
    // Create an array of pairs where each pair consists of A[i] and its index
    vector<Node> nodes(N);
    for (int i = 0; i < N; ++i) {
        nodes[i].val = A[i];
        nodes[i].idx = i;
    }

    // Sort the nodes array based on the values of A in descending order
    sort(nodes.begin(), nodes.end(), cmp);

    // Calculate prefix sums of B
    vector<ll> prefixSum(N + 1);
    for (int i = 1; i <= N; ++i) {
        prefixSum[i] = prefixSum[i - 1] + B[nodes[i - 1].idx];
    }

    // Initialize variables to store the result
    ll res = INF;
    for (int i = K - 1; i < N; ++i) {
        // Calculate the current result using the maximum value of A and the sum of corresponding B values
        res = min(res, (prefixSum[i + 1] - prefixSum[i - K + 1]) * nodes[i].val);
    }

    // Output the result
    cout << res << '\n';
}

int main() {
    ios_base::sync_with_stdio(false); cin.tie(0); cout.tie(0);

    int T;
    cin >> T;
    while (T--) {
        int N, K;
        cin >> N >> K;
        vector<ll> A(N), B(N);
        for (int i = 0; i < N; ++i) cin >> A[i];
        for (int i = 0; i < N; ++i) cin >> B[i];

        solve(N, K, A, B);
    }

    return 0;
}