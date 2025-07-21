#include <bits/stdc++.h>

using namespace std;

using ll = long long;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);

    int N, K;
    cin >> N >> K;

    vector<ll> A(N);
    for (int i = 0; i < N; ++i) {
        cin >> A[i];
    }

    // We need to find the minimum possible value of max(B) - min(B)
    // after removing exactly K elements from A.
    // The best strategy is to remove the K largest elements if K is odd.
    // If K is even, we can remove the K largest and the K smallest elements.
    sort(A.begin(), A.end());

    // If K is odd, remove the last K elements (largest).
    if (K % 2 == 1) {
        cout << A[N - 1] - A[N - K - 1] << endl;
    } else {
        // If K is even, remove the last K and the first K elements (largest and smallest).
        cout << A[N - 1] - A[K] << endl;
    }

    return 0;
}