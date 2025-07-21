#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    int N, K;
    cin >> N >> K;
    vector<int> A(N);
    for (auto& val : A) {
        cin >> val;
    }
    sort(A.begin(), A.end());
    int min_diff = A.back() - A.front();
    for (int i = 0; i <= K; ++i) {
        int j = i + (N - K) - 1;
        if (j >= N) break;
        min_diff = min(min_diff, A[j] - A[i]);
    }
    cout << min_diff << endl;
    return 0;
}