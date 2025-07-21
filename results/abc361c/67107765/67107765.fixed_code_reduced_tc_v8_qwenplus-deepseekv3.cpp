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
    for (int i = 0; i <= K; ++i) {
        int j = N - 1 - (K - i);
        ll current_diff = A[j] - A[i];
        if (current_diff < min_diff) {
            min_diff = current_diff;
        }
    }
    cout << min_diff << endl;
    return 0;
}