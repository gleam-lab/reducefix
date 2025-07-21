#include <bits/stdc++.h>
using namespace std;

int main() {
    int N, K;
    cin >> N >> K;
    vector<int> A(N);
    for (int i = 0; i < N; ++i) {
        cin >> A[i];
    }
    
    int result = INT_MAX;
    for (int i = 0; i <= K; ++i) {
        int left = i;
        int right = N - (K - i);
        if (left >= right) continue;
        int current_min = *min_element(A.begin() + left, A.begin() + right);
        int current_max = *max_element(A.begin() + left, A.begin() + right);
        result = min(result, current_max - current_min);
    }
    
    cout << result << endl;
    return 0;
}