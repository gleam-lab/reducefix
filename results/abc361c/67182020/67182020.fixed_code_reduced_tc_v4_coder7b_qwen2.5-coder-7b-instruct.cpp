#include <bits/stdc++.h>
using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int N, K;
    cin >> N >> K;
    vector<int> A(N);
    for (int i = 0; i < N; ++i) {
        cin >> A[i];
    }

    sort(A.begin(), A.end());

    if (K % 2 == 0) {
        int mid = K / 2;
        cout << A[N - 1 - mid] - A[mid] << endl;
    } else {
        int mid = K / 2;
        cout << min(A[N - 1 - mid] - A[mid + 1], A[N - 2 - mid] - A[mid]) << endl;
    }

    return 0;
}