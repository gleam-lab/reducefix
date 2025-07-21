#include <bits/stdc++.h>
using namespace std;

int main() {
    ios_base::sync_with_stdio(false);
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
        int result = A[N - mid] - A[mid];
        cout << result << endl;
    } else {
        int mid1 = K / 2;
        int mid2 = (K + 1) / 2;
        int result1 = A[N - mid1] - A[mid1 + 1];
        int result2 = A[N - mid2] - A[mid2];
        cout << min(result1, result2) << endl;
    }

    return 0;
}