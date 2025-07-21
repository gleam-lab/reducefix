#include <bits/stdc++.h>
using namespace std;

#define int long long

void solve() {
    int N, K;
    cin >> N >> K;
    vector<int> A(N);
    for (int i = 0; i < N; ++i) {
        cin >> A[i];
    }
    
    int min_diff = LLONG_MAX;
    for (int i = 0; i <= K; ++i) {
        int left = i;
        int right = N - (K - i);
        if (left > right) continue;
        int current_min = *min_element(A.begin() + left, A.begin() + right);
        int current_max = *max_element(A.begin() + left, A.begin() + right);
        min_diff = min(min_diff, current_max - current_min);
    }
    cout << min_diff << endl;
}

signed main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    solve();
    return 0;
}