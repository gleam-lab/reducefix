#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

typedef long long ll;

struct Element {
    ll value;
    int index;
};

bool compareByValue(const Element &a, const Element &b) {
    return a.value > b.value;
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0);

    int T;
    cin >> T;

    while (T--) {
        int N, K;
        cin >> N >> K;

        vector<Element> A(N);
        for (int i = 0; i < N; ++i) {
            cin >> A[i].value;
            A[i].index = i;
        }

        vector<Element> B(N);
        for (int i = 0; i < N; ++i) {
            cin >> B[i].value;
            B[i].index = i;
        }

        // Sort A in descending order and B in ascending order
        sort(A.begin(), A.end(), compareByValue);
        sort(B.begin(), B.end());

        // Calculate the result
        ll result = 0;
        for (int i = 0; i < K; ++i) {
            result += A[i].value * B[i].value;
        }

        cout << result << '\n';
    }

    return 0;
}