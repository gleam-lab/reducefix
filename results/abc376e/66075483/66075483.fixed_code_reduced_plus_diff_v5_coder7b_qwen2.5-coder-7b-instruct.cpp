#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;

#define ll long long

struct Pair {
    ll a, b;
};

bool compare(Pair p1, Pair p2) {
    return p1.a * p2.b < p2.a * p1.b;
}

int main() {
    ios_base::sync_with_stdio(false); cin.tie(0); cout.tie(0);

    int T;
    cin >> T;

    while (T--) {
        int N, K;
        cin >> N >> K;

        vector<ll> A(N), B(N);
        for (int i = 0; i < N; ++i) cin >> A[i];
        for (int i = 0; i < N; ++i) cin >> B[i];

        vector<Pair> pairs(N);
        for (int i = 0; i < N; ++i) {
            pairs[i] = {A[i], B[i]};
        }

        sort(pairs.begin(), pairs.end(), compare);

        ll result = 0;
        for (int i = 0; i < K; ++i) {
            result += pairs[i].a * pairs[i].b;
        }

        cout << result << '\n';
    }

    return 0;
}