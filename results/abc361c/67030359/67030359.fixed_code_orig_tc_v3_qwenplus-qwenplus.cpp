#include <bits/stdc++.h>

using namespace std;

#define all(x) x.begin(), x.end()
#define eb emplace_back
#define chmin(a, b) if (a > b) a = b

typedef long long ll;
typedef vector<int> vi;

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    int N, K;
    cin >> N >> K;
    vi A(N);
    for (int i = 0; i < N; ++i) {
        cin >> A[i];
    }

    // We will use sliding window on the sorted array to find minimum max-min difference
    sort(all(A));

    // We need to remove exactly K elements, so we want to choose a subsequence of length N-K
    // that minimizes (max - min)

    // Sliding window: maintain a window of size (N-K)
    int res = INT_MAX;
    for (int i = 0; i + (N - K) <= N; ++i) {
        int j = i + (N - K);
        chmin(res, A[j - 1] - A[i]);
    }

    cout << res << endl;
    return 0;
}