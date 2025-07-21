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
    
    multiset<long long> boxes(B.begin(), B.end());
    vector<long long> unmatched;
    
    for (long long toy : A) {
        auto it = boxes.lower_bound(toy);
        if (it != boxes.end()) {
            boxes.erase(it);
        } else {
            unmatched.push_back(toy);
        }
    }
    
    if (unmatched.size() == 1) {
        cout << unmatched[0] << endl;
    } else if (unmatched.size() == 0) {
        // All toys matched, but we still need to use the new box (x can be 1)
        cout << 1 << endl;
    } else {
        cout << -1 << endl;
    }
}

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    solve();
    return 0;
}