#include <bits/stdc++.h>
using namespace std;

#define fi first
#define se second
#define pb push_back
#define chmax(x, y) x = max(x, y)
#define chmin(x, y) x = min(x, y)

using ll = long long;
using P = pair<int, int>;

const int INF = 1001001001;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int N, K;
    cin >> N >> K;
    vector<int> A(N);
    for (int i = 0; i < N; ++i) {
        cin >> A[i];
    }

    // We need to remove exactly K elements to minimize (max(B) - min(B))
    // where B is the sequence of remaining N-K elements in original order

    // Sliding window approach: consider all windows of size L = N - K
    // and find the one with minimal (max - min)

    int L = N - K;
    deque<int> min_deque;  // stores indices, values increasing
    deque<int> max_deque;  // stores indices, values decreasing
    int ans = INT_MAX;

    for (int i = 0; i < N; ++i) {
        // Maintain min_deque
        while (!min_deque.empty() && A[min_deque.back()] >= A[i])
            min_deque.pop_back();
        min_deque.push_back(i);

        // Maintain max_deque
        while (!max_deque.empty() && A[max_deque.back()] <= A[i])
            max_deque.pop_back();
        max_deque.push_back(i);

        // Remove out-of-window indices
        if (i >= L - 1) {
            while (min_deque.front() <= i - L)
                min_deque.pop_front();
            while (max_deque.front() <= i - L)
                max_deque.pop_front();

            chmin(ans, A[max_deque.front()] - A[min_deque.front()]);
        }
    }

    cout << ans << endl;
}