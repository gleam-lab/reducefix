#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;

#define ll long long

struct Element {
    ll val, index;
};

// Comparator to sort based on the value in descending order
bool compare(const Element &a, const Element &b) {
    return a.val > b.val;
}

ll solve(int n, int k, vector<ll>& A, vector<ll>& B) {
    // Create pairs of A and B values with their indices
    vector<Element> AB(n);
    for(int i = 0; i < n; ++i) {
        AB[i] = {A[i], i};
    }

    // Sort based on the values of A in descending order
    sort(AB.begin(), AB.end(), compare);

    // Calculate prefix sums of B values
    vector<ll> prefixSum(n + 1);
    for(int i = 0; i < n; ++i) {
        prefixSum[i + 1] = prefixSum[i] + B[AB[i].index];
    }

    // Find the minimum value of (max(A_i)) * (sum(B_i))
    ll result = LLONG_MAX;
    for(int i = 0; i <= n - k; ++i) {
        result = min(result, AB[i].val * (prefixSum[i + k] - prefixSum[i]));
    }

    return result;
}

int main() {
    ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);

    int t;
    cin >> t;
    while(t--) {
        int n, k;
        cin >> n >> k;

        vector<ll> A(n), B(n);
        for(int i = 0; i < n; ++i) {
            cin >> A[i];
        }
        for(int i = 0; i < n; ++i) {
            cin >> B[i];
        }

        cout << solve(n, k, A, B) << "\n";
    }

    return 0;
}