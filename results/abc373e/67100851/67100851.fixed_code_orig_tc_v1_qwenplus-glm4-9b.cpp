#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

const int MAX_N = 200000;
long long A[MAX_N];
long long psum[MAX_N + 1];

// binary search to find the minimum votes needed
long long getmin(int idx) {
    long long x = A[idx];
    long long l = -1, r = A[idx] - M + 1;
    while (l < r) {
        long long mid = (l + r + 1) / 2;
        long long s = 0;
        for (int i = idx; i >= 0 && A[i] + mid >= A[idx]; i--) {
            s += A[i];
        }
        s = psum[idx + 1] - s + A[idx] + mid;
        for (int i = idx + 1; i < idx + M && A[i] > A[idx] + mid; i++) {
            s += psum[i + 1] - psum[i];
        }
        if (K - s >= mid) {
            r = mid - 1;
        } else {
            l = mid;
        }
    }
    return l;
}

int main() {
    int N, M, K;
    cin >> N >> M >> K;
    for (int i = 0; i < N; i++) {
        cin >> A[i];
    }
    sort(A, A + N, greater<long long>());
    psum[0] = 0;
    for (int i = 0; i < N; i++) {
        psum[i + 1] = psum[i] + A[i];
    }

    vector<long long> ans(N, 0);
    for (int i = 0; i < N; i++) {
        ans[i] = getmin(i);
        if (ans[i] == -1) {
            ans[i] = 0;
        }
    }

    for (int i = 0; i < N; i++) {
        if (A[i] + ans[i] > A[i + 1] + ans[i + 1]) {
            ans[i] = max(ans[i], A[i + 1] + ans[i + 1] - A[i] - ans[i]);
        }
    }

    for (int i = 0; i < N; i++) {
        if (ans[i] == -1) {
            cout << -1 << " ";
        } else {
            cout << ans[i] << " ";
        }
    }
    cout << endl;

    return 0;
}