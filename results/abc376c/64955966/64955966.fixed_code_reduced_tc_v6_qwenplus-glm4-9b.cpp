#include<bits/stdc++.h>
#define ll long long
using namespace std;

int main() {
    ll N;
    cin >> N;
    ll A[N], B[N-1];
    for (int i = 0; i < N; i++) cin >> A[i];
    for (int i = 0; i < N-1; i++) cin >> B[i];

    // Sort the toy sizes in descending order
    sort(A, A+N, greater<ll>());

    // Initialize the result as the largest size in B (since that box is used)
    ll result = B[N-2];

    // Iterate through the toy sizes
    for (int i = 0; i < N; i++) {
        // If the current toy size is less than or equal to the result, update result
        if (A[i] <= result) {
            continue;
        }

        // If the current toy size is larger than the result, we need to buy a new box
        // The size of this new box should be the current toy size
        result = A[i];

        // If the result is larger than the largest size in B, we cannot proceed
        if (result > B[N-2]) {
            cout << -1 << endl;
            return 0;
        }
    }

    cout << result << endl;
    return 0;
}