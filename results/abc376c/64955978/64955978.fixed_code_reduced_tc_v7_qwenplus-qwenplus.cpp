#include <bits/stdc++.h>
using namespace std;

void solve() {
    int N;
    cin >> N;
    vector<long long> A(N), B(N - 1);

    for (int i = 0; i < N; ++i) {
        cin >> A[i];
    }
    for (int i = 0; i < N - 1; ++i) {
        cin >> B[i];
    }

    sort(A.begin(), A.end());
    sort(B.begin(), B.end());

    multiset<long long> boxSizes;
    int j = 0;
    for (int i = 0; i < N; ++i) {
        // While current toy doesn't fit in current box, add boxes to multiset
        while (j < N - 1 && B[j] < A[i]) {
            boxSizes.insert(B[j]);
            j++;
        }

        if (j < N - 1) {
            // Use this box directly
            j++;
        } else if (!boxSizes.empty()) {
            // Use the smallest available box
            boxSizes.erase(boxSizes.begin());
        } else {
            // No suitable box
            cout << -1 << endl;
            return;
        }
    }

    // Find the minimum size of the additional box needed
    long long minBoxSize = 0;
    for (int i = 0; i < N - 1; ++i) {
        minBoxSize = max(minBoxSize, B[i] - A[i]);
    }
    minBoxSize = max(minBoxSize, A[N - 1] - B[N - 2]);

    cout << minBoxSize << endl;
}

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    solve();
    return 0;
}