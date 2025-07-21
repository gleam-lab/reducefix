#include <iostream>
#include <vector>
#include <algorithm>
#include <cmath>

using namespace std;

const int INF = 1e9 + 7;

int main() {
    int N, Q;
    cin >> N >> Q;

    vector<long long> A(N + 1);
    for (int i = 1; i <= N; ++i) {
        cin >> A[i];
    }

    for (int j = 0; j < Q; ++j) {
        long long b, k;
        cin >> b >> k;
        vector<long long> distances(N + 1);

        for (int i = 1; i <= N; ++i) {
            distances[i] = abs(A[i] - b);
        }

        sort(distances.begin(), distances.begin() + N);

        cout << distances[k - 1] << endl;
    }

    return 0;
}