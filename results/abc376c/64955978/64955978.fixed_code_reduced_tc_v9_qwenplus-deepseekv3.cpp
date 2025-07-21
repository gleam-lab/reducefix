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
    
    vector<bool> used(N-1, false);
    int j = 0;
    int unmatched = -1;
    
    for (int i = 0; i < N; ++i) {
        while (j < N-1 && (used[j] || B[j] < A[i])) {
            ++j;
        }
        if (j < N-1) {
            used[j] = true;
        } else {
            if (unmatched == -1) {
                unmatched = A[i];
            } else {
                cout << -1 << endl;
                return;
            }
        }
    }
    
    if (unmatched == -1) {
        cout << 1 << endl; // All toys fit in existing boxes, but we need to purchase at least one box, so x can be 1
    } else {
        cout << unmatched << endl;
    }
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    
    solve();
    
    return 0;
}