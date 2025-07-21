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

    int window_size = N - K;
    ll min_diff = LLONG_MAX;

    for (int i = 0; i + window_size <= N; ++i) {
        min_diff = min(min_diff, 1LL * A[i + window_size - 1] - A[i]);
    }

    cout << min_diff << endl;

    return 0;
}