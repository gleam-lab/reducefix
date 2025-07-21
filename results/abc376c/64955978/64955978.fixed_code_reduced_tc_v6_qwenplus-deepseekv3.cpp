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
    
    int a_ptr = 0, b_ptr = 0;
    vector<int> remaining;
    
    while (a_ptr < N && b_ptr < N-1) {
        if (A[a_ptr] <= B[b_ptr]) {
            a_ptr++;
            b_ptr++;
        } else {
            remaining.push_back(A[a_ptr]);
            a_ptr++;
        }
    }
    
    while (a_ptr < N) {
        remaining.push_back(A[a_ptr]);
        a_ptr++;
    }
    
    if (remaining.size() != 1) {
        cout << -1 << endl;
        return;
    }
    
    cout << remaining[0] << endl;
}

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    
    solve();
    
    return 0;
}