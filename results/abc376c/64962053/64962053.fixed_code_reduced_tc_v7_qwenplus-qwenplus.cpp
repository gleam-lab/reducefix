#include <bits/stdc++.h>
using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int N;
    cin >> N;
    vector<long long> A(N), B(N - 1);
    for (int i = 0; i < N; ++i) cin >> A[i];
    for (int i = 0; i < N - 1; ++i) cin >> B[i];

    sort(A.begin(), A.end());
    sort(B.begin(), B.end());

    multiset<long long> bSet;
    for (long long b : B) bSet.insert(b);

    // Try to match smallest toys with smallest boxes first
    for (int i = 0; i < N - 1; ++i) {
        auto it = bSet.lower_bound(A[i]);
        if (it == bSet.end()) {
            cout << -1 << endl;
            return 0;
        }
        bSet.erase(it);
    }

    // The last toy needs to go into the new box
    cout << A.back() << endl;
    return 0;
}