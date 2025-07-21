#include <bits/stdc++.h>
using namespace std;
#define fi first
#define se second
#define pb push_back
#define chmax(x, y) x = max(x, y)
#define chmin(x, y) x = min(x, y)

using ll = long long;
using P = pair<int, int>;

const ll INF = 1e18;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    int N, K;
    cin >> N >> K;
    vector<int> A(N);
    for (int i = 0; i < N; ++i) {
        cin >> A[i];
    }

    // We need to remove K elements such that the remaining sequence has minimum (max - min)
    // Since we must keep N-K elements, and they must be in original order,
    // sliding window of size (N-K) is a valid candidate for B.
    int window_size = N - K;
    int min_diff = INF;

    // Sliding window approach
    multiset<int> window;
    for (int i = 0; i < N; ++i) {
        window.insert(A[i]);
        if (i >= window_size) {
            window.erase(window.find(A[i - window_size]));
        }
        if (i >= window_size - 1 && !window.empty()) {
            chmin(min_diff, *window.rbegin() - *window.begin());
        }
    }

    cout << min_diff << '\n';
}