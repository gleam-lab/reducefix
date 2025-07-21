#include <iostream>
#include <vector>
#include <algorithm>
#include <numeric>
#include <cmath>

using namespace std;

typedef long long ll;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int N, M;
    ll K;
    cin >> N >> M >> K;

    vector<ll> A(N);
    for(int i = 0; i < N; ++i) {
        cin >> A[i];
        K -= A[i];
    }

    sort(A.begin(), A.end());

    vector<ll> S(N + 1);
    for(int i = 0; i < N; ++i) {
        S[i + 1] = S[i] + A[i];
    }

    vector<ll> C(N);
    for(int i = 0; i < N; ++i) {
        if(A[i] > S.back() - A[i]) {
            C[i] = -1;
        } else {
            ll need = (M - 1) * (S.back() - A[i]) - S[i];
            if(need <= K) {
                C[i] = need;
            } else {
                C[i] = -1;
            }
        }
    }

    for(int i = 0; i < N; ++i) {
        cout << C[i] << " ";
    }
    cout << endl;

    return 0;
}