#include <bits/stdc++.h>
using namespace std;

int main() {
    int N, K;
    cin >> N >> K;
    vector<int> A(N);
    for (int i = 0; i < N; ++i) {
        cin >> A[i];
    }
    
    vector<pair<int, int>> indexedA(N);
    for (int i = 0; i < N; ++i) {
        indexedA[i] = {A[i], i};
    }
    sort(indexedA.begin(), indexedA.end());
    
    int min_diff = INT_MAX;
    for (int i = 0; i <= K; ++i) {
        int left = indexedA[i].first;
        int right = indexedA[N - K + i - 1].first;
        min_diff = min(min_diff, right - left);
    }
    
    cout << min_diff << endl;
    return 0;
}