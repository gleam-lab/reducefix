#include <bits/stdc++.h>
#define ll long long
using namespace std;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);

    int N;
    cin >> N;

    vector<ll> A(N), B(N - 1);
    for (int i = 0; i < N; ++i) cin >> A[i];
    for (int i = 0; i < N - 1; ++i) cin >> B[i];

    // Sort A in ascending order
    sort(A.begin(), A.end());

    // Sort B in descending order
    sort(B.rbegin(), B.rend());

    // Initialize index for B
    int j = 0;

    for (int i = 0; i < N; ++i) {
        if (j == N - 1 || A[i] > B[j]) {
            // No suitable box found for the current toy
            cout << -1 << endl;
            return 0;
        }
        while (j < N - 1 && A[i] <= B[j]) {
            ++j;
        }
    }

    // The smallest box size needed is the last box used
    cout << B.back() << endl;

    return 0;
}