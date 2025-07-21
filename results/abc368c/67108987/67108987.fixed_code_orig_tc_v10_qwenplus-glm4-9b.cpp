#include<bits/stdc++.h>

using namespace std;

int main() {
    int N;
    cin >> N;
    vector<int> H(N + 9);
    for (int i = 1; i <= N; i++) cin >> H[i];

    long long T = 0;

    // For every group of 3 enemies, deal 9 damage
    for (int i = 0; i < N - 2; i += 3) {
        if (H[i] > 0) T += (H[i] / 3) * 3 + (H[i] % 3 == 0 ? 1 : 2);
        if (H[i + 1] > 0) T += (H[i + 1] / 3) * 3 + (H[i + 1] % 3 == 0 ? 1 : 2);
        if (H[i + 2] > 0) T += (H[i + 2] / 3) * 3 + (H[i + 2] % 3 == 0 ? 1 : 2);
    }

    // Calculate the remaining damage for the last 1 to 2 enemies
    if (N % 3 == 1 && H[N - 1] > 0) {
        T += H[N - 1];
    } else if (N % 3 == 2 && H[N - 2] > 0) {
        T += H[N - 2] + 2;
    }

    cout << T << endl;
    return 0;
}