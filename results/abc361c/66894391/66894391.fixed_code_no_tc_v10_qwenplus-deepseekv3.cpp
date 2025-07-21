#include <bits/stdc++.h>
using namespace std;

int main() {
    int N, K;
    cin >> N >> K;
    vector<int> A(N);
    for (int i = 0; i < N; ++i) {
        cin >> A[i];
    }
    sort(A.begin(), A.end());
    
    int min_range = INT_MAX;
    for (int left_remove = 0; left_remove <= K; ++left_remove) {
        int right_remove = K - left_remove;
        int current_min = A[left_remove];
        int current_max = A[N - 1 - right_remove];
        min_range = min(min_range, current_max - current_min);
    }
    
    cout << min_range << endl;
    return 0;
}