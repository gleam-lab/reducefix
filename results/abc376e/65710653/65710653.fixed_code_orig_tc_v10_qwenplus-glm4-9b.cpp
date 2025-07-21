#include <iostream>
#include <vector>
#include <algorithm>
#include <tuple>

using namespace std;
using ll = long long;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int T;
    cin >> T;

    while (T--) {
        int N, K;
        cin >> N >> K;

        vector<tuple<int, int>> A(N);  // Pair of (A_i, B_i)
        for (int i = 0; i < N; ++i) {
            cin >> get<0>(A[i]);
            cin >> get<1>(A[i]);
        }

        // Sort based on A values
        sort(A.begin(), A.end());

        // Calculate the sum of the smallest K B values
        ll sum_B = 0;
        for (int i = 0; i < K; ++i) {
            sum_B += get<1>(A[i]);
        }

        // The result is the product of the largest A value in the top K and sum_B
        cout << get<0>(A[K-1]) * sum_B << endl;
    }

    return 0;
}