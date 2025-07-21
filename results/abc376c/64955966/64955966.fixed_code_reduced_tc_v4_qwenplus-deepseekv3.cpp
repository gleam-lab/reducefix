#include<bits/stdc++.h>
using namespace std;

void solve() {
    int N;
    cin >> N;
    vector<int> A(N), B(N-1);
    for (int i = 0; i < N; ++i) cin >> A[i];
    for (int i = 0; i < N-1; ++i) cin >> B[i];
    
    sort(A.begin(), A.end(), greater<int>());
    sort(B.begin(), B.end(), greater<int>());
    
    int i = 0, j = 0;
    int count = 0;
    while (i < N && j < N-1) {
        if (A[i] <= B[j]) {
            ++i;
            ++j;
            ++count;
        } else {
            ++i;
        }
    }
    
    if (count >= N-1) {
        cout << 1 << endl;
    } else if (count == N-2 && A.back() <= B.back()) {
        cout << A[N-2] << endl;
    } else {
        int remaining = N - count;
        if (remaining == 1) {
            cout << A.back() << endl;
        } else {
            cout << -1 << endl;
        }
    }
}

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    
    solve();
    
    return 0;
}