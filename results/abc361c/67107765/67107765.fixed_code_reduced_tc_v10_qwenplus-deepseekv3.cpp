#include <bits/stdc++.h>
using namespace std;
#define ll long long

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    int N, K;
    cin >> N >> K;
    vector<ll> A(N);
    for (int i = 0; i < N; ++i) {
        cin >> A[i];
    }
    sort(A.begin(), A.end());
    ll min_diff = LLONG_MAX;
    for (int i = 0; i + (N - K) - 1 < N; ++i) {
        min_diff = min(min_diff, A[i + (N - K) - 1] - A[i]);
    }
    cout << min_diff << endl;
    return 0;
}