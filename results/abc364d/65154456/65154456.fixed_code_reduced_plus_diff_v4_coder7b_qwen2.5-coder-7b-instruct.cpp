#include <bits/stdc++.h>

using namespace std;

const int MAXN = 100005;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0);

    int N, Q;
    cin >> N >> Q;

    vector<int> A(N);
    for (int i = 0; i < N; ++i) {
        cin >> A[i];
    }

    for (int q = 0; q < Q; ++q) {
        int B, k;
        cin >> B >> k;

        vector<int> distances;
        for (int i = 0; i < N; ++i) {
            distances.push_back(abs(A[i] - B));
        }

        sort(distances.begin(), distances.end());

        cout << distances[k - 1] << '\n';
    }

    return 0;
}