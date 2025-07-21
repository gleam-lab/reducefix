#include <iostream>
#include <vector>
#include <map>
#include <numeric>

using namespace std;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0);

    int N;
    cin >> N;
    vector<long long> X(N), P(N + 1);
    P[0] = 0;
    for (int i = 0; i < N; ++i) {
        cin >> X[i];
    }
    for (int i = 0; i < N; ++i) {
        long long p;
        cin >> p;
        P[i + 1] = P[i] + p;
    }

    map<long long, int> x_to_ptr;
    for (int i = 0; i < N; ++i) {
        x_to_ptr[X[i]] = i;
    }

    int Q;
    cin >> Q;
    while (Q--) {
        int L, R;
        cin >> L >> R;
        auto X_l = x_to_ptr.lower_bound(L);
        auto X_r = x_to_ptr.upper_bound(R);
        int l = (X_l == x_to_ptr.end()) ? N : X_l->second;
        int r = (X_r == x_to_ptr.end()) ? N : X_r->second;
        cout << P[r] - P[l] << '\n';
    }

    return 0;
}