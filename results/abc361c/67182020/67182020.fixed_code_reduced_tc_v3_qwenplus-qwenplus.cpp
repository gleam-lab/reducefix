#include <bits/stdc++.h>
using namespace std;
using ll = long long;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);

    int N, K;
    cin >> N >> K;
    vector<int> A(N);
    for (int i = 0; i < N; ++i) {
        cin >> A[i];
    }

    // Sort the array
    sort(A.begin(), A.end());

    // The result is the minimum difference between max and min in any window of size (N - K)
    ll min_diff = LLONG_MAX;
    for (int i = 0; i + (N - K) <= N; ++i) {
        min_diff = min(min_diff, (ll)A[i + (N - K)] - (ll)A[i]);
    }

    cout << min_diff << endl;
    return 0;
}