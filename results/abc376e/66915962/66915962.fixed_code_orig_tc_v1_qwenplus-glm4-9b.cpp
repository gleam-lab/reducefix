#include <iostream>
#include <vector>
#include <algorithm>
#include <iomanip>
using namespace std;

int main() {
    int t;
    cin >> t;
    while (t--) {
        int N, K;
        cin >> N >> K;
        vector<int> A(N), B(N);
        vector<pair<int, int>> indices(N);
        for (int i = 0; i < N; ++i) {
            cin >> A[i];
            indices[i] = {A[i], B[i]};
        }
        sort(indices.begin(), indices.end(), [](const pair<int, int>& a, const pair<int, int>& b) {
            return a.first < b.first;
        });

        long long minans = LLONG_MAX;
        if (K == 1) {
            minans = indices[0].first * indices[0].second;
        } else if (K == N) {
            long long sumB = 0;
            for (int i = 0; i < N; ++i) {
                minans = min(minans, indices[i].first * (sumB += indices[i].second));
            }
        } else {
            vector<long long> prefixB(N, 0);
            prefixB[0] = indices[0].second;
            for (int i = 1; i < N; ++i) {
                prefixB[i] = prefixB[i - 1] + indices[i].second;
            }

            long long low = 0, high = prefixB.back();
            while (low <= high) {
                long long mid = (low + high) / 2;
                long long maxA = 0;
                int count = 0;
                for (int i = 0; i < N && count < K; ++i) {
                    if (prefixB[i] <= mid) {
                        maxA = max(maxA, indices[i].first);
                        count++;
                    }
                }
                if (count == K) {
                    minans = min(minans, maxA * mid);
                    high = mid - 1;
                } else {
                    low = mid + 1;
                }
            }
        }
        cout << minans << '\n';
    }
}