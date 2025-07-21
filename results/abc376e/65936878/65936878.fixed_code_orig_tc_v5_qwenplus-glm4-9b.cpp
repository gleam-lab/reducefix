#include <iostream>
#include <vector>
#include <algorithm>
#include <set>
using namespace std;

int32_t main() {
    int T;
    cin >> T;
    while (T--) {
        int N, K;
        cin >> N >> K;
        vector<int> A(N), B(N);
        for (int i = 0; i < N; ++i) {
            cin >> A[i];
        }
        for (int i = 0; i < N; ++i) {
            cin >> B[i];
        }
        
        // Pair elements from A and B and sort by A[i]
        vector<pair<int, int>>AB(N);
        for (int i = 0; i < N; ++i) {
            AB[i] = {A[i], B[i]};
        }
        sort(AB.begin(), AB.end());
        
        // Use a greedy approach with a two-pointer technique
        long long sumB = 0, maxA = AB[0].first;
        set<int> S;
        for (int i = 0; i < N; ++i) {
            sumB += AB[i].second;
            S.insert(AB[i].second);
            if (S.size() > K) {
                sumB -= *S.begin();
                S.erase(S.begin());
            }
        }
        
        cout << maxA * sumB << '\n';
    }
    return 0;
}