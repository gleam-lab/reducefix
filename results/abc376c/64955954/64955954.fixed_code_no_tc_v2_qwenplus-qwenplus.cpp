#include <bits/stdc++.h>
using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int N;
    cin >> N;
    vector<long long> A(N);
    vector<long long> B(N - 1);

    for (int i = 0; i < N; ++i) {
        cin >> A[i];
    }
    for (int i = 0; i < N - 1; ++i) {
        cin >> B[i];
    }

    sort(A.begin(), A.end());
    sort(B.begin(), B.end());

    // Check if it's possible to fit toys into boxes with one extra box
    // We will try to assign the largest toy to the extra box
    // and match the rest greedily

    // Binary search on x (size of extra box)
    long long low = 1, high = 1e18;
    long long answer = -1;

    while (low <= high) {
        long long mid = (low + high) / 2;
        // Try to assign toys to boxes with extra box of size mid

        vector<long long> tempB = B;
        tempB.push_back(mid);
        sort(tempB.begin(), tempB.end());

        bool ok = true;
        for (int i = 0; i < N; ++i) {
            if (tempB[i] < A[i]) {
                ok = false;
                break;
            }
        }

        if (ok) {
            answer = mid;
            high = mid - 1;
        } else {
            low = mid + 1;
        }
    }

    cout << answer << '\n';
    return 0;
}