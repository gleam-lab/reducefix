#include <bits/stdc++.h>
using namespace std;
#define fi first
#define se second
#define pb push_back
#define chmax(x, y) x = max(x, y)
#define chmin(x, y) x = min(x, y)

using ll = long long;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    
    int N, K;
    cin >> N >> K;
    vector<int> A(N);
    for (int i = 0; i < N; ++i) {
        cin >> A[i];
    }

    // We need to choose N-K elements in order to minimize the difference between
    // the max and min in that subsequence. Try all windows of size N-K and find min difference.

    int window_size = N - K;
    int res = numeric_limits<int>::max();
    multiset<int> ms;

    for (int i = 0; i < N; ++i) {
        ms.insert(A[i]);
        if (i >= window_size - 1) {
            // Window from [i - window_size + 1, i]
            int mn = *ms.begin();
            int mx = *ms.rbegin();
            chmin(res, mx - mn);
            ms.erase(ms.find(A[i - window_size + 1]));
        }
    }

    cout << res << endl;
}