#include <iostream>
#include <vector>
#include <map>
#include <algorithm>
using namespace std;

int main() {
    int N, Q;
    cin >> N >> Q;

    vector<int> A(N);
    for (int i = 0; i < N; ++i) {
        cin >> A[i];
    }
    sort(A.begin(), A.end());

    vector<pair<int, int>> BQ(Q);
    for (int i = 0; i < Q; ++i) {
        cin >> BQ[i].first >> BQ[i].second;
    }

    map<int, int> M;
    for (int i = 0; i < N; ++i) {
        M[A[i]] = A[i];
    }

    for (auto &bq : BQ) {
        int B = bq.first;
        int k = bq.second;

        int l = -1, r = N;
        while (r - l > 1) {
            int m = (l + r) / 2;
            int Bplus = B + A[m] > 0 ? 1 : 0;
            int Bminus = B + A[m] < 0 ? 1 : 0;

            int count = 0;
            if (Bplus) {
                count += M[B + A[m]];
            }
            if (Bminus) {
                count += M[-1 - (B + A[m])];
            }

            if (count >= k) {
                r = m;
            } else {
                l = m;
            }
        }

        cout << abs(B + A[l]) << endl;
    }

    return 0;
}