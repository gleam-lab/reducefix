#include <bits/stdc++.h>
using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int N;
    cin >> N;
    vector<long long> H(N);
    for (int i = 0; i < N; ++i) {
        cin >> H[i];
    }

    long long T = 0;

    for (int i = 0; i < N; ++i) {
        long long h = H[i];

        // Full cycles: each cycle has 3 attacks (deals 5 damage total: 1+1+3)
        long long cycles = h / 5;
        T += cycles * 3;
        h -= cycles * 5;

        if (h > 0) {
            // Apply remaining attacks manually
            T++;
            if (T % 3 == 0) h -= 3;
            else h--;

            if (h > 0) {
                T++;
                if (T % 3 == 0) h -= 3;
                else h--;
            }
            if (h > 0) {
                T++;
                if (T % 3 == 0) h -= 3;
                else h--;
            }
        }
    }

    cout << T << endl;
    return 0;
}