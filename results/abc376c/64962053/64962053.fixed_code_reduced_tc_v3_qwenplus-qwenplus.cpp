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

    multiset<long long> boxSizes;
    for (long long b : B) {
        boxSizes.insert(b);
    }

    // Try to place each toy into a suitable box greedily
    for (int i = 0; i < N; ++i) {
        auto it = boxSizes.lower_bound(A[i]);
        if (it == boxSizes.end()) {
            // No box can accommodate this toy, so we need to use the new box
            cout << A[i] << endl;
            return 0;
        }
        boxSizes.erase(it); // Use up this box
    }

    // If we managed to place all toys without needing the new box
    cout << -1 << endl;
    return 0;
}