#include <iostream>
#include <vector>
#include <queue>
#include <algorithm>

using namespace std;

typedef long long ll;

int main() {
    int t;
    cin >> t;
    while (t--) {
        int n, k;
        cin >> n >> k;
        vector<int> A(n), B(n);
        
        // Read sequences A and B
        for (int i = 0; i < n; ++i) {
            cin >> A[i];
        }
        for (int i = 0; i < n; ++i) {
            cin >> B[i];
        }
        
        // Pair A and B and sort by A
        vector<pair<int, int>> AB(n);
        for (int i = 0; i < n; ++i) {
            AB[i] = {A[i], B[i]};
        }
        sort(AB.begin(), AB.end(), [](const pair<int, int>& a, const pair<int, int>& b) {
            return a.first < b.first;
        });

        // Min-heap to maintain the sum of the largest K elements from B
        priority_queue<int, vector<int>, greater<int>> pq;
        int sumB = 0, minProduct = LLONG_MAX;

        // Calculate the sum of the top K elements from B for the first window
        for (int i = 0; i < k; ++i) {
            pq.push(AB[i].second);
            sumB += AB[i].second;
        }

        // Update the minimum product for the first window
        minProduct = min(minProduct, sumB * AB[k-1].first);

        // Slide the window over A
        for (int i = k; i < n; ++i) {
            sumB += AB[i].second - pq.top();
            pq.pop();
            minProduct = min(minProduct, sumB * AB[i].first);
        }

        // Output the minimum product for this test case
        cout << minProduct << endl;
    }

    return 0;
}