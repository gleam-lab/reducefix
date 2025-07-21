#include<bits/stdc++.h>
using namespace std;
#define int long long

signed main() {
    ios::sync_with_stdio(0), cin.tie(0), cout.tie(0);
    int N, M, K;
    cin >> N >> M >> K;
    vector<int> A(N);
    for (int i = 0; i < N; ++i) {
        cin >> A[i];
    }
    vector<int> sorted_A = A;
    sort(sorted_A.begin(), sorted_A.end(), greater<int>());
    int threshold = (M <= N) ? sorted_A[M - 1] : 0;
    int remaining_votes = K;
    for (int i = 0; i < N; ++i) {
        remaining_votes -= A[i];
    }
    for (int i = 0; i < N; ++i) {
        int current = A[i];
        if (current >= threshold) {
            cout << "0 ";
        } else {
            int needed = threshold - current + 1;
            if (needed <= remaining_votes) {
                cout << needed << " ";
            } else {
                cout << "-1 ";
            }
        }
    }
    return 0;
}