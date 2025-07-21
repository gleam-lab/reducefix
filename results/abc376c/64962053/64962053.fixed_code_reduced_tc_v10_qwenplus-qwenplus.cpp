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

    multiset<long long> b_set;
    for (long long val : B) b_set.insert(val);

    // Try to fit the smallest toys into the smallest boxes first
    for (int i = 0; i < N - 1; ++i) {
        auto it = b_set.lower_bound(A[i]);
        if (it == b_set.end()) {
            cout << -1 << endl;
            return 0;
        }
        b_set.erase(it);
    }

    // The last toy must go into the new box
    cout << A.back() << endl;
    return 0;
}