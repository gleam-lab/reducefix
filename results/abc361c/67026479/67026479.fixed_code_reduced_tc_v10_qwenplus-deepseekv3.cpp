#include <bits/stdc++.h>
using namespace std;

int main() {
    int N, K;
    cin >> N >> K;
    vector<int> A(N);
    for (int i = 0; i < N; ++i) {
        cin >> A[i];
    }
    
    int M = N - K;
    if (M == 0) {
        cout << 0 << endl;
        return 0;
    }
    
    multiset<int> window;
    for (int i = 0; i < M; ++i) {
        window.insert(A[i]);
    }
    
    int min_diff = *window.rbegin() - *window.begin();
    
    for (int i = M; i < N; ++i) {
        window.erase(window.find(A[i - M]));
        window.insert(A[i]);
        int current_diff = *window.rbegin() - *window.begin();
        if (current_diff < min_diff) {
            min_diff = current_diff;
        }
    }
    
    cout << min_diff << endl;
    return 0;
}