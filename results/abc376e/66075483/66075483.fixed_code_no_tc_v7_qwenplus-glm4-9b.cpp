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
        vector<pair<long long, long long>> A(N);
        vector<pair<long long, long long>> B(N);
        
        for (int i = 0; i < N; i++) {
            cin >> A[i].first;
            A[i].second = i;
        }
        for (int i = 0; i < N; i++) {
            cin >> B[i].first;
            B[i].second = i;
        }

        // Sort by A values to ensure we always pick the smallest K A values
        sort(A.begin(), A.end());
        // Prepare sorted B values according to the sorted A indices
        vector<pair<long long, long long>> sortedB(N);
        for (int i = 0; i < N; i++) {
            sortedB[A[i].second] = B[i];
        }

        long long answer = LONG_LONG_MAX;
        long long sumB = 0;
        // Iterate up to K-1 elements in sorted B to find the minimum possible sum of B elements
        for (int i = 0; i < K - 1; i++) {
            sumB += sortedB[i].first;
            answer = min(answer, sortedB[i].first * (sumB - sortedB[i].first));
        }
        
        cout << answer << endl;
    }
    return 0;
}