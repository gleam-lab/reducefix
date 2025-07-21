#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;

#define ll long long

struct Pair {
    ll first, second;
};

// Comparator function to sort pairs in descending order based on first element
bool comp(Pair &a, Pair &b) {
    return a.first > b.first;
}

ll solve(int n, int k, vector<ll>& A, vector<ll>& B) {
    vector<Pair> AB(n);
    for (int i = 0; i < n; ++i) {
        AB[i] = {A[i], B[i]};
    }

    // Sort the pairs based on the first element (A)
    sort(AB.begin(), AB.end(), comp);

    // Compute prefix sums for B
    vector<ll> prefixSum(n + 1, 0);
    for (int i = 0; i < n; ++i) {
        prefixSum[i + 1] = prefixSum[i] + AB[i].second;
    }

    ll minProduct = LLONG_MAX;

    // Sliding window to find the minimum product
    for (int i = 0; i <= n - k; ++i) {
        ll currentMax = AB[i].first;
        ll currentSum = prefixSum[i + k] - prefixSum[i];
        ll product = currentMax * currentSum;
        minProduct = min(minProduct, product);
    }

    return minProduct;
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

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

        ll result = solve(n, k, A, B);
        cout << result << "\n";
    }

    return 0;
}