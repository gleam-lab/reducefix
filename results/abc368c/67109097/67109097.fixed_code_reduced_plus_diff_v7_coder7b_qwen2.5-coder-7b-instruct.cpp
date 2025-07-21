#include <bits/stdc++.h>
using namespace std;

int main() {
    int N;
    cin >> N;
    vector<int> H(N);
    for (int i = 0; i < N; i++) cin >> H[i];

    long long T = 0;
    while (true) {
        bool anyHit = false;
        for (int i = 0; i < N; i++) {
            if (H[i] > 0) {
                anyHit = true;
                if ((T + 1) % 3 == 0) H[i] -= 3;
                else H[i]--;
                T++;
            }
        }
        if (!anyHit) break;
    }

    cout << T << endl;
    return 0;
}