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

    for (long long h : H) {
        if (h == 0) continue;

        // Each cycle consists of 2*1 + 3 = 5 damage
        long long full_cycles = h / 5;
        long long rem = h % 5;

        T += full_cycles * 3;

        if (rem > 0) {
            T += (T % 3 == 0 ? 3 : (T % 3));
            long long remaining_damage = rem;
            while (remaining_damage > 0) {
                if (T % 3 == 0) {
                    remaining_damage -= 3;
                } else {
                    remaining_damage -= 1;
                }
                T++;
            }
        }
    }

    cout << T << endl;
    return 0;
}