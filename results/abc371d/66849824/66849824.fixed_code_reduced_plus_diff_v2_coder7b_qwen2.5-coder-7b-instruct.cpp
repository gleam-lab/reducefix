#include <iostream>
#include <vector>
#include <map>
#include <algorithm>
using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int N;
    cin >> N;
    vector<long long> A(N);
    vector<long long> P(N + 1);
    P[0] = 0;

    for (int i = 0; i < N; ++i) {
        cin >> A[i];
        P[i + 1] = P[i] + A[i];
    }

    map<long long, int> pos;
    for (int i = 0; i < N; ++i) {
        pos[A[i]] = i;
    }

    int Q;
    cin >> Q;
    while (Q--) {
        int L, R;
        cin >> L >> R;
        auto itL = pos.lower_bound(L);
        auto itR = pos.upper_bound(R);

        if (itL == pos.end()) {
            cout << P[N] << '\n';
        } else {
            int l = itL->second + 1;
            if (itR != pos.begin()) {
                --itR;
                int r = itR->second + 1;
                cout << P[r] - P[l] << '\n';
            } else {
                cout << P[l] << '\n';
            }
        }
    }

    return 0;
}