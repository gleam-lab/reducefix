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

    sort(A.begin(), A.end());

    ll minDiff = LLONG_MAX;
    for (int i = 0; i + (N - K - 1) < N; ++i) {
        minDiff = min(minDiff, (ll)A[i + (N - K - 1)] - (ll)A[i]);
    }

    cout << minDiff << endl;
    return 0;
}