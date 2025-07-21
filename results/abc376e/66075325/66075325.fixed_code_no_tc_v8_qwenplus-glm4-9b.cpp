#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

#define MAXN 200010
long long A[MAXN], B[MAXN];
vector<pair<long long, long long>> V;

int main() {
    int T, N, K;
    cin >> T;
    while (T--) {
        cin >> N >> K;
        V.clear();

        for (int i = 0; i < N; i++) {
            cin >> A[i];
        }
        for (int i = 0; i < N; i++) {
            cin >> B[i];
            V.emplace_back(B[i], A[i]);
        }

        sort(V.begin(), V.end());

        long long ans = LLONG_MAX;
        long long sumB = 0, sumA = 0;
        int count = 0;

        // Traverse from the end to find the minimum possible value
        for (int i = N - 1; i >= 0; i--) {
            sumB += V[i].first;
            sumA += V[i].second;
            count++;

            // If we have more than K elements, we can start removing
            if (count > K) {
                sumA -= V[i + K].second;
                sumB -= V[i + K].first;
                count--;
            }

            // If we have exactly K elements, we can calculate the current answer
            if (count == K) {
                ans = min(ans, sumB * V[i].second);
            }
        }

        cout << ans << endl;
    }

    return 0;
}