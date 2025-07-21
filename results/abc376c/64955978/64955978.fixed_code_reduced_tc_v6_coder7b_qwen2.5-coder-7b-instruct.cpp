#include <bits/stdc++.h>

using namespace std;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);

    int N;
    cin >> N;

    vector<long long> A(N), B(N-1);
    for (int i = 0; i < N; ++i) cin >> A[i];
    for (int i = 0; i < N-1; ++i) cin >> B[i];

    // Sort toy sizes and box sizes
    sort(A.begin(), A.end());
    sort(B.begin(), B.end());

    // Try to fit each toy into the smallest available box
    bool placed[N] = {false};
    for (int i = 0; i < N; ++i) {
        bool found = false;
        for (int j = 0; j < N-1; ++j) {
            if (!placed[j] && A[i] <= B[j]) {
                placed[j] = true;
                found = true;
                break;
            }
        }
        if (!found) {
            cout << -1 << endl;
            return 0;
        }
    }

    // Find the maximum box size used
    long long maxBoxSize = *max_element(B.begin(), B.end());
    // The minimum additional box size needed is the next size greater than the maximum box size
    cout << maxBoxSize + 1 << endl;

    return 0;
}