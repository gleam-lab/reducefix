#include <iostream>
#include <vector>
#include <queue>
using namespace std;

int main() {
    int t, n, k;
    cin >> t;
    while (t--) {
        cin >> n >> k;
        vector<int> A(n), B(n);
        for (int i = 0; i < n; i++) cin >> A[i];
        for (int i = 0; i < n; i++) cin >> B[i];
        
        vector<pair<int, int>> v(n);
        for (int i = 0; i < n; i++) v[i] = {A[i], B[i]};
        sort(v.begin(), v.end(), greater<pair<int, int>>());

        int minVal = INT_MAX;
        priority_queue<int, vector<int>, greater<int>> pq;
        long long sum = 0;

        // Calculate sum of B values for the top k elements
        for (int i = 0; i < k; i++) {
            sum += v[i].second;
            pq.push(v[i].second);
        }

        // Calculate the expression for this initial subset
        minVal = min(minVal, v[0].first * sum);

        // Slide the window
        for (int i = k; i < n; i++) {
            sum += v[i].second - pq.top();
            pq.pop();
            pq.push(v[i].second);
            minVal = min(minVal, v[i].first * sum);
        }

        cout << minVal << endl;
    }
    return 0;
}