#include <iostream>
#include <vector>
#include <map>

using namespace std;
using ll = long long;

int dx[4] = {1, 0, -1, 0};
int dy[4] = {0, 1, 0, -1};

int main() {
    int N;
    cin >> N;
    vector<int> P(N + 1), X(N);
    P[0] = 0;
    for (int i = 0; i < N; ++i) {
        cin >> X[i];
        P[i + 1] = P[i] + X[i];
    }

    int Q;
    cin >> Q;
    for (int q = 0; q < Q; ++q) {
        int L, R;
        cin >> L >> R;
        auto itL = upper_bound(X.begin(), X.end(), L);
        auto itR = upper_bound(X.begin(), X.end(), R);
        itR--; // Adjust because upper_bound gives one past the last element

        // Check if the bounds are within the range
        if (itL == X.begin() || *itL > R) {
            cout << "0" << endl;
        } else if (itR == X.end() || *itR < L) {
            cout << "0" << endl;
        } else {
            cout << P[*itR] - P[*itL - 1] << endl;
        }
    }
}