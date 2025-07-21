#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int main() {
    int N, K;
    cin >> N >> K;
    vector<int> A(N);
    for (int i = 0; i < N; ++i) {
        cin >> A[i];
    }

    sort(A.begin(), A.end());

    int min_diff = INT_MAX;
    for (int highç«¯ = 0; highç«¯ <= K; ++highç«¯) {
        int lowç«¯ = K - highç«¯;
        int max_value = A[N-1-highç«¯];
        int min_value = A[lowç«¯];
        min_diff = min(min_diff, max_value - min_value);
    }

    cout << min_diff << endl;
    return 0;
}