#include <bits/stdc++.h>

using namespace std;

int main() {
    int N;
    cin >> N;
    vector<long long> H(N);
    for (int i = 0; i < N; ++i) {
        cin >> H[i];
    }

    long long T = 0;

    for (long long h : H) {
        // We will apply as many full cycles of 3 attacks (damage 5) as possible
        long long full_cycles = h / 5;
        long long rem = h % 5;
        T += full_cycles * 3;

        // Apply the remaining damage (less than 5)
        while (rem > 0) {
            T++;
            if (T % 3 == 0) {
                rem -= 3;
            } else {
                rem -= 1;
            }
        }
    }

    cout << T << endl;
    return 0;
}