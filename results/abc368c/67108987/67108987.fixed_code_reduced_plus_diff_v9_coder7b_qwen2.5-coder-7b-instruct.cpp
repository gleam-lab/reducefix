#include <bits/stdc++.h>
using namespace std;

int main() {
    int N;
    cin >> N;
    vector<long long> H(N);
    for (int i = 0; i < N; i++) cin >> H[i];

    long long T = 0;
    bool changed = true;

    while (changed) {
        changed = false;
        for (int i = 0; i < N; i++) {
            if (H[i] > 0) {
                changed = true;
                if (T % 3 == 0) {
                    H[i] -= 3;
                } else {
                    H[i]--;
                }
                T++;
            }
        }
    }

    cout << T << endl;
    return 0;
}