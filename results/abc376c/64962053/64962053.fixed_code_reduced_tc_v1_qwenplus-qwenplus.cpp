#include <bits/stdc++.h>
using namespace std;

int main() {
    int N;
    cin >> N;
    vector<long long> A(N), B(N - 1);

    for (int i = 0; i < N; ++i) cin >> A[i];
    for (int i = 0; i < N - 1; ++i) cin >> B[i];

    sort(A.begin(), A.end());
    sort(B.begin(), B.end());

    multiset<long long> boxSizes;
    for (long long b : B) boxSizes.insert(b);

    // Try to assign toys greedily
    for (int i = N - 1; i >= 0; --i) {
        auto it = boxSizes.lower_bound(A[i]);
        if (it == boxSizes.end()) {
            // Can't fit this toy in any available box, need to add a new box
            cout << A[i] << endl;
            return 0;
        }
        boxSizes.erase(it); // Use up this box
    }

    // All toys fit without needing a new box
    cout << -1 << endl;
    return 0;
}