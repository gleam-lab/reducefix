#include <iostream>
#include <vector>
#include <queue>
#include <algorithm>
using namespace std;

int main() {
    int t;
    cin >> t;

    while (t--) {
        int n, k;
        cin >> n >> k;

        vector<int> a(n), b(n);
        for (int i = 0; i < n; ++i) {
            cin >> a[i];
        }
        for (int i = 0; i < n; ++i) {
            cin >> b[i];
        }

        vector<array<int, 2>> arr(n); // Array to store pairs (A_i, B_i)
        for (int i = 0; i < n; ++i) {
            arr[i] = {a[i], b[i]};
        }

        sort(arr.begin(), arr.end(), [](const array<int, 2>& a, const array<int, 2>& b) {
            return a[0] > b[0]; // Sort in descending order of A_i
        });

        priority_queue<int, vector<int>, greater<int>> pq; // Min-heap for sum of B_i values
        long long sum = 0, min_value = long long(1e18);
        for (int i = 0; i < n; ++i) {
            pq.push(arr[i][1]);
            if (i >= k) {
                sum -= pq.top();
                pq.pop();
            }
            if (i < k) {
                sum += arr[i][1];
            }
            min_value = min(min_value, arr[i][0] * sum);
        }

        cout << min_value << endl;
    }

    return 0;
}