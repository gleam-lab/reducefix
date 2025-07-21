#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int main() {
    int T;
    cin >> T;
    while (T--) {
        int N, K;
        cin >> N >> K;
        vector<long long> A(N), B(N);
        
        for (int i = 0; i < N; ++i) {
            cin >> A[i];
        }
        for (int i = 0; i < N; ++i) {
            cin >> B[i];
        }

        // Sort A and B by A values
        vector<pair<long long, long long>> ab(N);
        for (int i = 0; i < N; ++i) {
            ab[i] = {A[i], B[i]};
        }
        sort(ab.begin(), ab.end());

        long long ans = LLONG_MAX;
        // Priority queue to store the sums of B_i for the last K elements
        priority_queue<long long, vector<long long>, greater<long long>> pq;
        long long s = 0; // Current sum of B_i for the last K elements

        for (int i = N - 1; i >= 0; --i) {
            pq.push(ab[i].second);
            s += ab[i].second;
            if (pq.size() > K) {
                s -= pq.top();
                pq.pop();
            }
            if (pq.size() == K) {
                ans = min(ans, pq.top() * s);
            }
        }

        cout << ans << endl;
    }
    return 0;
}