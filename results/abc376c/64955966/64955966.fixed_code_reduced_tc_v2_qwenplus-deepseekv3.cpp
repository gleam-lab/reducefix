#include<bits/stdc++.h>
using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int N;
    cin >> N;
    vector<int> A(N), B(N-1);
    for (int i = 0; i < N; ++i) cin >> A[i];
    for (int i = 0; i < N-1; ++i) cin >> B[i];

    sort(A.begin(), A.end(), greater<int>());
    sort(B.begin(), B.end(), greater<int>());

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
        cout << 1 << endl; // Though all are matched, we still need to buy a box (can be any size >=1)
    } else {
        cout << unmatched[0] << endl;
    }

    return 0;
}