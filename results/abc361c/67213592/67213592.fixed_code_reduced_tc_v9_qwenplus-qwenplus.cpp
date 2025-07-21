#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int N, K;
    cin >> N >> K;
    vector<long long> A(N);
    for (auto& a : A) {
        cin >> a;
    }

    sort(A.begin(), A.end());

    long long result = A[N - 1] - A[0];

    for (int i = 0; i + (N - K) <= N; ++i) {
        int j = i + (N - K) - 1;
        result = min(result, A[j] - A[i]);
    }

    cout << result << endl;

    return 0;
}