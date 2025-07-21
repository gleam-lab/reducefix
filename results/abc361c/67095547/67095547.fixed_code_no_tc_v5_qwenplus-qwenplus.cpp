#include <bits/stdc++.h>
using namespace std;

#define endl "\n"
#define int long long

typedef long long ll;
typedef pair<int, int> pii;

void solve() {
    int n, k;
    cin >> n >> k;
    vector<int> A(n);
    for (int i = 0; i < n; ++i) {
        cin >> A[i];
    }

    // We will keep exactly (n - K) elements in the result
    int windowSize = n - k;
    
    // Sort the array to allow sliding window minimum/maximum queries
    vector<pii> sortedA(n);
    for (int i = 0; i < n; ++i) {
        sortedA[i] = {A[i], i};
    }
    sort(sortedA.begin(), sortedA.end());

    // Initialize answer with a large value
    int ans = numeric_limits<int>::max();

    // Two pointers to maintain a sliding window of size windowSize
    int left = 0;
    int right = 0;
    deque<int> minIdx, maxIdx;

    while (right < n) {
        // Add current index to deques
        while (!minIdx.empty() && A[minIdx.back()] >= A[right]) minIdx.pop_back();
        while (!maxIdx.empty() && A[maxIdx.back()] <= A[right]) maxIdx.pop_back();
        minIdx.push_back(right);
        maxIdx.push_back(right);

        // If window is larger than windowSize, remove elements from front
        while (right - left + 1 > windowSize) {
            if (minIdx.front() == left) minIdx.pop_front();
            if (maxIdx.front() == left) maxIdx.pop_front();
            left++;
        }

        // When window size is achieved, update answer
        if (right - left + 1 == windowSize) {
            ans = min(ans, A[maxIdx.front()] - A[minIdx.front()]);
        }

        right++;
    }

    cout << ans << endl;
}

signed main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    solve();
    return 0;
}