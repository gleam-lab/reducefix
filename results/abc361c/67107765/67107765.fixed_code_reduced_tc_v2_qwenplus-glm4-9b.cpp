#include <bits/stdc++.h>
using namespace std;

const int MAXN = 200001;
int N, K, A[MAXN];

int main() {
    cin >> N >> K;
    for (int i = 0; i < N; ++i) {
        cin >> A[i];
    }

    // Compute prefix min and suffix max
    vector<int> prefixMin(N);
    vector<int> suffixMax(N);
    prefixMin[0] = A[0];
    for (int i = 1; i < N; ++i) {
        prefixMin[i] = min(prefixMin[i - 1], A[i]);
    }
    suffixMax[N - 1] = A[N - 1];
    for (int i = N - 2; i >= 0; --i) {
        suffixMax[i] = max(suffixMax[i + 1], A[i]);
    }

    // Calculate the minimum possible value of the maximum value of B minus the minimum value of B
    int minRange = INF;
    for (int i = 0; i <= K; ++i) {
        for (int l = 0; l <= N - i; ++l) {
            int r = l + i;
            int minB = prefixMin[l];
            int maxB = suffixMax[r - 1];
            minRange = min(minRange, maxB - minB);
        }
    }

    cout << minRange << endl;
    return 0;
}