#include <bits/stdc++.h>

using namespace std;

int main() {
    int N;
    cin >> N;
    vector<long long> H(N + 1);
    for (int i = 1; i <= N; ++i) {
        cin >> H[i];
    }

    long long T = 0;

    for (int i = 1; i <= N; ++i) {
        // Each group of 3 attacks deals 5 damage: two 1s and one 3
        long long fullGroups = H[i] / 5;
        long long remainder = H[i] % 5;

        T += fullGroups * 3;

        // Apply remaining damage
        while (remainder--) {
            if (T % 3 == 0) {
                remainder -= 3;
            } else {
                remainder -= 1;
            }
            T++;
        }
    }

    cout << T << endl;
    return 0;
}