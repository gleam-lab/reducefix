#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;

#define ll long long

struct Pair {
    ll first, second;
};

bool compare(const Pair &a, const Pair &b) {
    return a.first > b.first || (a.first == b.first && a.second < b.second);
}

ll minExpression(int n, int k, vector<ll> &A, vector<ll> &B) {
    vector<Pair> pairs(n);
    for (int i = 0; i < n; ++i) {
        pairs[i] = {A[i], B[i]};
    }

    // Sort pairs based on A[i] in descending order. If A[i] is the same, sort by B[i] in ascending order.
    sort(pairs.begin(), pairs.end(), compare);

    vector<ll> prefixSum(n + 1);
    for (int i = 0; i < n; ++i) {
        prefixSum[i + 1] = prefixSum[i] + pairs[i].second;
    }

    ll result = LLONG_MAX;
    for (int i = 0; i <= n - k; ++i) {
        ll currentMax = pairs[i].first;
        ll currentSum = prefixSum[i + k] - prefixSum[i];
        result = min(result, currentMax * currentSum);
    }

    return result;
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);

    int t;
    cin >> t;
    while (t--) {
        int n, k;
        cin >> n >> k;
        vector<ll> A(n), B(n);
        for (int i = 0; i < n; ++i) {
            cin >> A[i];
        }
        for (int i = 0; i < n; ++i) {
            cin >> B[i];
        }

        cout << minExpression(n, k, A, B) << endl;
    }

    return 0;
}