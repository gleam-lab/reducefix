#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;
#define int long long

int solve(int n, int k, vector<int>& A, vector<int>& B) {
    vector<pair<int, int>> AB(n);
    for (int i = 0; i < n; ++i) {
        AB[i] = {A[i], B[i]};
    }
    sort(AB.begin(), AB.end(), [](const pair<int, int>& a, const pair<int, int>& b) {
        return a.first < b.first;
    });

    int result = INT_MAX;
    int sum = 0;
    vector<int> maxK(B.begin(), B.begin() + k);
    sort(maxK.begin(), maxK.end(), greater<int>());

    for (int i = 0; i < n; ++i) {
        sum += AB[i].second;
        if (i >= k - 1) {
            sum -= maxK[k - 2]; // We remove the smallest element from the first k elements
            result = min(result, AB[i].first * sum);
            sum += maxK[k - 2]; // We add the smallest element back to sum
        }
    }

    return result;
}

int32_t main() {
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