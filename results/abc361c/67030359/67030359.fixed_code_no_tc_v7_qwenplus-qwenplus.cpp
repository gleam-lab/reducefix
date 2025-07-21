#include <bits/stdc++.h>

using namespace std;

#define all(x) (x).begin(), (x).end()
#define fi first
#define se second
#define pb push_back
#define mp make_pair
#define endl '\n'

typedef long long ll;
typedef pair<int, int> pii;
typedef vector<int> vi;

const int INF = 1e9 + 7;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);

    int N, K;
    cin >> N >> K;
    vi A(N);
    for (int i = 0; i < N; ++i) {
        cin >> A[i];
    }

    // We want to remove exactly K elements from A to minimize max(B) - min(B)
    // where B is the resulting sequence after removing K elements.
    // The key is that we must keep (N - K) elements, and they must be in order.
    //
    // So the problem reduces to finding a window of size (N - K) in A such that
    // (max in window) - (min in window) is minimized.

    // Use a sliding window and two deques to track min and max in window
    deque<int> dq_min, dq_max;
    int res = INF;

    for (int i = 0; i < N; ++i) {
        // Maintain dq_min: increasing sequence
        while (!dq_min.empty() && A[dq_min.back()] >= A[i]) dq_min.pop_back();
        dq_min.push_back(i);

        // Maintain dq_max: decreasing sequence
        while (!dq_max.empty() && A[dq_max.back()] <= A[i]) dq_max.pop_back();
        dq_max.push_back(i);

        // Remove out-of-window indices
        if (dq_min.front() <= i - (N - K)) dq_min.pop_front();
        if (dq_max.front() <= i - (N - K)) dq_max.pop_front();

        // Once the window reaches size (N - K), compute diff
        if (i >= (N - K) - 1) {
            res = min(res, A[dq_max.front()] - A[dq_min.front()]);
        }
    }

    cout << res << endl;
}