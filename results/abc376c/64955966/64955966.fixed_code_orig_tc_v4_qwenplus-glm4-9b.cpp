#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    int N;
    cin >> N;
    vector<int> A(N), B(N - 1);
    for (int i = 0; i < N; ++i) {
        cin >> A[i];
    }
    for (int i = 0; i < N - 1; ++i) {
        cin >> B[i];
    }
    sort(A.begin(), A.end());
    vector<bool> used(N - 1, false);
    int x = 0, lastBoxSize = 0;

    for (int i = 0; i < N; ++i) {
        bool placed = false;
        for (int j = 0; j < N - 1 && !placed; ++j) {
            if (B[j] >= A[i] && !used[j]) {
                used[j] = true;
                x = max(x, B[j]);
                placed = true;
            }
        }
        if (!placed) {
            cout << -1 << endl;
            return 0;
        }
    }

    cout << x << endl;
    return 0;
}