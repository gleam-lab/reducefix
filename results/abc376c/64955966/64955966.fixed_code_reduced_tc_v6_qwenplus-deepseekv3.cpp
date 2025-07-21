#include<bits/stdc++.h>
using namespace std;

void solve() {
    int N;
    cin >> N;
    vector<long long> A(N), B(N-1);
    for (int i = 0; i < N; ++i) cin >> A[i];
    for (int i = 0; i < N-1; ++i) cin >> B[i];
    
    sort(A.begin(), A.end(), greater<long long>());
    sort(B.begin(), B.end(), greater<long long>());
    
    int i = 0, j = 0;
    vector<long long> unmatched;
    while (i < N && j < N-1) {
        if (A[i] <= B[j]) {
            i++;
            j++;
        } else {
            unmatched.push_back(A[i]);
            i++;
        }
    }
    while (i < N) {
        unmatched.push_back(A[i]);
        i++;
    }
    
    if (unmatched.size() > 1) {
        cout << -1 << endl;
        return;
    } else if (unmatched.size() == 1) {
        cout << unmatched[0] << endl;
    } else {
        cout << 1 << endl;
    }
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    
    solve();
    
    return 0;
}