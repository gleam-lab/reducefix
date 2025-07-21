#include <iostream>
#include <vector>
#include <map>

using namespace std;

int main() {
    int N;
    cin >> N;
    vector<int> X(N);  // X should be of size N, not N+1 as it's not used
    for (int i = 0; i < N; ++i) {
        cin >> X[i];
    }
    
    int Q;
    cin >> Q;
    vector<int> P(N + 1);
    P[0] = 0;
    for (int i = 0; i < N; ++i) {
        int p;
        cin >> p;
        P[i + 1] = P[i] + p;
    }

    for (int q = 0; q < Q; ++q) {
        int L, R;
        cin >> L >> R;
        int l = upper_bound(X.begin(), X.end(), L) - X.begin();
        int r = upper_bound(X.begin(), X.end(), R) - X.begin();
        cout << P[r] - P[l] << endl;
    }
    
    return 0;
}