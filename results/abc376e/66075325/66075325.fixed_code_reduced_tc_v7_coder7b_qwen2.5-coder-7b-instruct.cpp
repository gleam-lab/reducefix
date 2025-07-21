#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;

#define ll long long

struct Element {
    ll value;
    int index;
};

bool cmp(const Element &a, const Element &b) {
    return a.value > b.value;
}

ll solve(int N, int K, vector<Element> &A, vector<Element> &B) {
    sort(A.begin(), A.end(), cmp);
    sort(B.begin(), B.end());

    ll min_value = LLONG_MAX;
    for (int i = 0; i <= N - K; ++i) {
        ll max_A = A[i].value;
        ll sum_B = 0;
        for (int j = 0; j < K; ++j) {
            sum_B += B[A[i + j].index];
        }
        min_value = min(min_value, max_A * sum_B);
    }

    return min_value;
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0);

    int T;
    cin >> T;
    while (T--) {
        int N, K;
        cin >> N >> K;

        vector<Element> A(N), B(N);
        for (int i = 0; i < N; ++i) {
            cin >> A[i].value;
            A[i].index = i;
        }
        for (int i = 0; i < N; ++i) {
            cin >> B[i].value;
            B[i].index = i;
        }

        ll result = solve(N, K, A, B);
        cout << result << '\n';
    }

    return 0;
}