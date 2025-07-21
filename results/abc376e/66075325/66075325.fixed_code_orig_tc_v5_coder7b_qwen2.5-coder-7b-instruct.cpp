#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;

#define ll long long

ll solve(int n, int k, vector<ll>& A, vector<ll>& B) {
    // Sort arrays A and B
    sort(A.begin(), A.end());
    sort(B.begin(), B.end());

    // Initialize variables
    ll ans = LLONG_MAX;
    ll prefix_sum_B[200001] = {0};
    prefix_sum_B[0] = B[0];

    // Calculate prefix sums for B
    for (int i = 1; i < n; ++i) {
        prefix_sum_B[i] = prefix_sum_B[i - 1] + B[i];
    }

    // Iterate through A to find the minimum value of the expression
    for (int i = k - 1; i < n; ++i) {
        ll max_A = A[i];
        ll sum_B = prefix_sum_B[i] - prefix_sum_B[i - k] + B[i - k];
        ans = min(ans, max_A * sum_B);
    }

    return ans;
}

int main() {
    ios_base::sync_with_stdio(false); cin.tie(NULL);

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

        cout << solve(n, k, A, B) << '\n';
    }

    return 0;
}