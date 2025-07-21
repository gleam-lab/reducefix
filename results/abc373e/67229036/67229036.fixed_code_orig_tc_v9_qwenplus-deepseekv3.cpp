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
    
    vector<int> sortedA = A;
    sort(sortedA.begin(), sortedA.end(), greater<int>());
    
    int threshold = (M == N) ? 0 : sortedA[M - 1];
    
    for (int i = 0; i < N; ++i) {
        if (M == N) {
            cout << "0 ";
            continue;
        }
        int required = max(0LL, threshold - A[i] + 1);
        if (required <= K) {
            cout << required << " ";
        } else {
            cout << "-1 ";
        }
    }
    
    return 0;
}