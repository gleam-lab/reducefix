#include <bits/stdc++.h>
using namespace std;

int main() {
    int N;
    cin >> N;
    vector<long long> H(N);
    for (int i = 0; i < N; ++i) cin >> H[i];

    long long T = 0;

    for (int i = 0; i < N; ++i) {
        long long h = H[i];
        if (h <= 0) continue;

        // Determine how many attacks are needed starting from current T
        // Each attack increases T by 1
        // Attack does 3 damage when T is multiple of 3, otherwise 1

        long long attack_count = 0;
        long long t = T + 1;
        long long sum = 0;

        while (sum < h) {
            if (t % 3 == 0)
                sum += 3;
            else
                sum += 1;
            ++attack_count;
            ++t;
        }

        T += attack_count;
    }

    cout << T << endl;
    return 0;
}