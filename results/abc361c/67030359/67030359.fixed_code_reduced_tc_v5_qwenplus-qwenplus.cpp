#include <bits/stdc++.h>

using namespace std;

#define all(x) x.begin(), x.end()
#define eb emplace_back
#define mp make_pair
#define endl '\n'

typedef long long ll;
typedef pair<int, int> pi;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);

    int N, K;
    cin >> N >> K;
    vector<int> A(N);
    for (int i = 0; i < N; ++i) {
        cin >> A[i];
    }

    // We need to find the minimum possible value of (max - min)
    // after removing exactly K elements from the array.
    // The key is that the remaining elements must preserve their order,
    // and we must choose a contiguous segment of length N-K.

    // So we are looking for the minimum (max - min) among all subarrays of size (N-K)

    int res = numeric_limits<int>::max();
    deque<int> maxdq, mindq;

    for (int i = 0; i < N; ++i) {
        // Remove out of window indices
        while (!maxdq.empty() && maxdq.front() <= i - (N - K)) maxdq.pop_front();
        while (!mindq.empty() && mindq.front() <= i - (N - K)) mindq.pop_front();

        // Maintain decreasing deque for max
        while (!maxdq.empty() && A[maxdq.back()] <= A[i]) maxdq.pop_back();
        // Maintain increasing deque for min
        while (!mindq.empty() && A[mindq.back()] >= A[i]) mindq.pop_back();

        maxdq.push_back(i);
        mindq.push_back(i);

        // Once window is valid
        if (i >= (N - K - 1) && (N - K) > 0) {
            res = min(res, A[maxdq.front()] - A[mindq.front()]);
        }
    }

    cout << res << endl;

    return 0;
}