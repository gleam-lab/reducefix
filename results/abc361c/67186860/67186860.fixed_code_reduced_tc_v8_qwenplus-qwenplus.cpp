#include <bits/stdc++.h>
using namespace std;

int main() {
    int N, K;
    cin >> N >> K;
    vector<int> A(N);
    for (int i = 0; i < N; ++i) {
        cin >> A[i];
    }

    if (K == 0) {
        cout << 0 << endl;
        return 0;
    }

    // Try all possible ways to remove K elements: i from front, (K-i) from back
    int result = numeric_limits<int>::max();
    for (int i = 0; i <= K; ++i) {
        int j = K - i;
        if (i + j > N) continue;

        multiset<int> window;
        for (int k = i; k < N - j; ++k) {
            window.insert(A[k]);
        }

        if (!window.empty()) {
            result = min(result, *window.rbegin() - *window.begin());
        }
    }

    cout << result << endl;
    return 0;
}