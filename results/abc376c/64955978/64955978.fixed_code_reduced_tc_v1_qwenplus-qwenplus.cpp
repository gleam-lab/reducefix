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

    multiset<long long> box_sizes;
    int j = 0;
    long long min_x = -1;

    for (int i = 0; i < N; ++i) {
        // Add all boxes that are <= A[i] to the multiset
        while (j < N - 1 && B[j] <= A[i]) {
            box_sizes.insert(B[j]);
            ++j;
        }

        if (!box_sizes.empty()) {
            // We can place A[i] in one of the available boxes
            box_sizes.erase(box_sizes.find(*box_sizes.begin()));
        } else {
            // Cannot place A[i], we need a new box of at least A[i]
            min_x = A[i];
            break;
        }
    }

    cout << min_x << endl;
}