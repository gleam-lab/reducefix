#include <bits/stdc++.h>
using namespace std;

int main() {
    int N;
    cin >> N;
    vector<long long> H(N + 9);
    for (int i = 1; i <= N; i++) cin >> H[i];
    long long T = 0;
    
    while (true) {
        bool changed = false;
        for (int i = 1; i <= N; i++) {
            if (H[i] > 0) {
                long long decrease = (T % 3 == 0) ? 3 : 1;
                if (H[i] >= decrease) {
                    H[i] -= decrease;
                    T++;
                    changed = true;
                }
            }
        }
        if (!changed) break;
    }
    
    cout << T << endl;
    return 0;
}