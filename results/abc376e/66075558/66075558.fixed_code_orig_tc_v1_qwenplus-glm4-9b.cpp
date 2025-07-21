#include <iostream>
#include <vector>
#include <algorithm>
#include <queue>
using namespace std;

int main() {
    int T, N, K;
    cin >> T;
    while (T--) {
        cin >> N >> K;
        vector<pair<int, int>> arr(N);
        for (int i = 0; i < N; i++) {
            cin >> arr[i].first >> arr[i].second;
        }
        sort(arr.begin(), arr.end(), [](const pair<int, int>& a, const pair<int, int>& b) {
            return a.first < b.first;
        });

        priority_queue<int, vector<int>, greater<int>> pq;
        long long ans = LLONG_MAX;
        long long sumB = 0;
        vector<int> B(N);

        // Fill B array with sorted B values according to sorted A values
        for (int i = 0; i < N; i++) {
            B[i] = arr[i].second;
        }

        // Calculate the answer
        for (int i = 0; i < N; i++) {
            sumB += B[i];
            pq.push(B[i]);
            if (pq.size() > K) {
                sumB -= pq.top();
                pq.pop();
            }
            if (pq.size() == K) {
                ans = min(ans, max(arr[i].first, K) * sumB);
            }
        }

        cout << ans << endl;
    }
    return 0;
}