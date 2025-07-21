#include <iostream>
#include <vector>
#include <map>

using namespace std;
using ll = long long;

int main() {
    int N;
    cin >> N;
    vector<ll> P(N+1);
    P[0] = 0;

    vector<int> X(N);
    for (int i = 0; i < N; ++i) {
        cin >> X[i];
    }

    for (int i = 0; i < N; ++i) {
        int p;
        cin >> p;
        P[i+1] = P[i] + p;
    }

    map<int, int> x_to_ptr;
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

        int l = X_l == x_to_ptr.begin() ? 0 : (*prev(X_l)).second + 1;
        int r = X_r == x_to_ptr.end() ? N : (*X_r).second + 1;

        cout << P[r] - P[l] << endl;
    }

    return 0;
}