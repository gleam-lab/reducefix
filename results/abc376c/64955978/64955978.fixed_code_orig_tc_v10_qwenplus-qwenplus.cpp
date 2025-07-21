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

    multiset<long long> toys(A.begin(), A.end());

    int j = 0;
    for (int i = 0; i < N - 1; ++i) {
        auto it = toys.lower_bound(B[j]);
        if (it != toys.end()) {
            toys.erase(it);
            j++;
        }
    }

    if (!toys.empty()) {
        cout << *toys.begin() << endl;
    } else {
        cout << -1 << endl;
    }

    return 0;
}