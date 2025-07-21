#include <bits/stdc++.h>

#define all(x) x.begin(), x.end()

using namespace std;

using ll = long long int;
using vi = vector<int>;

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    int N, K;
    cin >> N >> K;
    vi A(N);
    for (int i = 0; i < N; i++) {
        cin >> A[i];
    }

    int leftMin = INT_MAX, rightMin = INT_MAX;
    for (int i = 0; i < N; i++) {
        leftMin = min(leftMin, A[i]);
    }
    for (int i = N - 1; i >= 0; i--) {
        rightMin = min(rightMin, A[i]);
    }

    ll minDiff = A[N - 1] - A[0]; // Initial difference

    sort(all(A)); // Sort the array

    // Try removing K elements from either side
    for (int i = 0; i <= K; i++) { // i elements from left, K-i from right
        ll leftDiff = A[i] - A[i + K - 1];
        minDiff = min(minDiff, leftDiff);
        leftMin = min(leftMin, A[i]);
        rightMin = min(rightMin, A[i + K - 1]);
    }

    // Try removing K elements from either side, but with reversed left part
    for (int i = 0; i <= K; i++) { // i elements from left, K-i from right
        ll rightDiff = A[N - 1 - i] - A[N - 1 - K + i];
        minDiff = min(minDiff, rightDiff);
        leftMin = min(leftMin, A[N - 1 - i]);
        rightMin = min(rightMin, A[N - 1 - K + i]);
    }

    cout << minDiff << endl;
    return 0;
}