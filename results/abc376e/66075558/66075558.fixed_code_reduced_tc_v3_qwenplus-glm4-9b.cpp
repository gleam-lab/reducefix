#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

struct Pair {
    int val;
    int index;
};

bool compare(Pair a, Pair b) {
    if (a.val == b.val) {
        return a.index < b.index;
    }
    return a.val > b.val;
}

int main() {
    int T;
    cin >> T;
    while (T--) {
        int N, K;
        cin >> N >> K;
        vector<Pair> A(N + 1), B(N + 1);

        for (int i = 0; i < N; i++) {
            cin >> A[i].val;
            A[i].index = i;
        }
        sort(A.begin() + 1, A.end(), compare);

        for (int i = 0; i < N; i++) {
            cin >> B[i].val;
            B[i].index = i;
        }
        sort(B.begin() + 1, B.end());

        int sumB = 0, minSum = INT_MAX;
        for (int i = 0; i < N; ++i) {
            sumB += B[i].val;
            if (i < K - 1) continue;

            int currentMaxA = A[i].val;
            int currentMinSum = min(sumB - B[i].val + B[A[i].index].val, minSum);

            minSum = min(minSum, currentMinSum);
        }

        cout << minSum << endl;
    }
    return 0;
}