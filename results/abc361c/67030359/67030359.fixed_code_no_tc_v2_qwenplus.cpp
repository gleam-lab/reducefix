#include <bits/stdc++.h>

#define all(x) x.begin(), x.end()

using namespace std;

using ll = long long int;
using vi = vector<int>;

template<typename T> inline bool chmin(T &a, T b) {
    if (a > b) {
        a = b;
        return true;
    }
    return false;
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);

    int N, K;
    cin >> N >> K;
    vi A(N);
    for (int i = 0; i < N; i++) {
        cin >> A[i];
    }
    sort(all(A));

    // We are removing exactly K elements, so we keep (N - K) elements.
    // The optimal strategy is to remove some number of elements from the left and right ends
    // because the array is sorted. We can try all possible splits:
    // Remove i elements from the left and (K - i) elements from the right, for i from 0 to K.
    int ans = A[N - 1] - A[0]; // worst case: no improvement

    for (int i = 0; i <= K; i++) {
        int left_removed = i;
        int right_removed = K - i;
        int remaining_left = left_removed;
        int remaining_right = N - 1 - right_removed;

        if (remaining_left <= remaining_right) {
            chmin(ans, A[remaining_right] - A[remaining_left]);
        }
    }

    cout << ans << endl;
    return 0;
}