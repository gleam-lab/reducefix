#include <iostream>
#include <vector>
#include <algorithm>
#include <queue>
using namespace std;

#define int long long
const int N = 2e5 + 9;

int solve(int n, int k, vector<int>& A, vector<int>& B) {
    vector<array<int, 2>> elements(N);
    for (int i = 0; i < n; ++i) {
        elements[i] = {A[i], B[i]};
    }
    sort(elements.begin(), elements.end());

    priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> pq;
    long long sumB = 0, maxA = 0, ans = LLONG_MAX;

    for (int i = 0; i < n; ++i) {
        sumB += elements[i][1];
        pq.push({elements[i][1], i + 1});  // Store index as i + 1 because it's 1-based
        if (pq.size() > k) {
            sumB -= pq.top().first;
            pq.pop();
        }

        if (pq.size() == k) {
            maxA = elements[i][0];
            ans = min(ans, maxA * sumB);
        }
    }

    return ans;
}

signed main() {
    int t;
    cin >> t;
    while (t--) {
        int n, k;
        cin >> n >> k;
        vector<int> A(n), B(n);
        for (int i = 0; i < n; ++i) cin >> A[i];
        for (int i = 0; i < n; ++i) cin >> B[i];
        cout << solve(n, k, A, B) << endl;
    }
    return 0;
}