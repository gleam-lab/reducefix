#include<bits/stdc++.h>

using namespace std;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    int N;
    cin >> N;
    vector<long long> H(N);
    for (int i = 0; i < N; i++) cin >> H[i];
    long long T = 0;
    for (int i = 0; i < N; i++) {
        long long h = H[i];
        if (h <= 0) continue;
        // Calculate the number of full cycles (5 damage per 3 attacks)
        long long full_cycles = h / 5;
        T += full_cycles * 3;
        h -= full_cycles * 5;
        if (h <= 0) continue;
        // Handle the remaining attacks
        while (h > 0) {
            T++;
            if (T % 3 == 0) {
                h -= 3;
            } else {
                h -= 1;
            }
        }
    }
    cout << T << endl;
    return 0;
}