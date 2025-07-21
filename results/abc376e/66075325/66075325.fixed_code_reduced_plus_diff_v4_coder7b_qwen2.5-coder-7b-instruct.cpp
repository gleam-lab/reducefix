#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

typedef pair<long long, long long> pii;

long long solve(int n, int k, vector<long long>& A, vector<long long>& B) {
    // Sort both arrays
    sort(A.begin(), A.end());
    sort(B.begin(), B.end());

    long long ans = LLONG_MAX;
    long long sumB = 0;

    // Calculate the initial sum of the first K elements of B
    for (int i = 0; i < k; ++i) {
        sumB += B[i];
    }

    // Iterate through A and update the answer
    for (int i = 0; i + k - 1 < n; ++i) {
        ans = min(ans, A[i] * sumB);
        if (i + k < n) {
            sumB -= B[i];
            sumB += B[i + k];
        }
    }

    return ans;
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0);

    int t;
    cin >> t;

    while (t--) {
        int n, k;
        cin >> n >> k;
        
        vector<long long> A(n), B(n);
        for (int i = 0; i < n; ++i) {
            cin >> A[i];
        }
        for (int i = 0; i < n; ++i) {
            cin >> B[i];
        }

        cout << solve(n, k, A, B) << endl;
    }

    return 0;
}