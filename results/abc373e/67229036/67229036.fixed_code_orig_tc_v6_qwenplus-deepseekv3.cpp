#include <bits/stdc++.h>
using namespace std;
#define int long long

signed main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    
    int N, M, K;
    cin >> N >> M >> K;
    vector<int> A(N);
    for (int i = 0; i < N; ++i) {
        cin >> A[i];
        K -= A[i];
    }
    
    if (N == M) {
        for (int i = 0; i < N; ++i) {
            cout << "0 ";
        }
        cout << "\n";
        return 0;
    }
    
    vector<int> sorted_A = A;
    sort(sorted_A.begin(), sorted_A.end(), greater<int>());
    int threshold = sorted_A[M - 1];
    
    for (int i = 0; i < N; ++i) {
        if (A[i] >= threshold) {
            cout << "0 ";
            continue;
        }
        int required = threshold - A[i] + 1;
        if (required <= K) {
            cout << required << " ";
        } else {
            cout << "-1 ";
        }
    }
    cout << "\n";
    
    return 0;
}