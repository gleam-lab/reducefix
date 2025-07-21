#include<bits/stdc++.h>
using namespace std;

void solve() {
    int N;
    cin >> N;
    vector<int> A(N), B(N-1);
    for (int i = 0; i < N; ++i) {
        cin >> A[i];
    }
    for (int i = 0; i < N-1; ++i) {
        cin >> B[i];
    }
    sort(A.begin(), A.end());
    sort(B.begin(), B.end());
    
    int i = 0, j = 0;
    vector<int> unmatched;
    while (i < N && j < N-1) {
        if (A[i] <= B[j]) {
            ++i;
            ++j;
        } else {
            unmatched.push_back(A[i]);
            ++i;
        }
    }
    while (i < N) {
        unmatched.push_back(A[i]);
        ++i;
    }
    
    if (unmatched.size() > 1) {
        cout << -1 << endl;
    } else if (unmatched.empty()) {
        cout << 1 << endl; // All toys fit in existing boxes, x can be any >=1, smallest is 1
    } else {
        cout << unmatched[0] << endl;
    }
}

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    solve();
    return 0;
}