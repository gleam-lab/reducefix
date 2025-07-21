#include<bits/stdc++.h>

using namespace std;

int main() {
    int N;
    cin >> N;
    vector<long long> H(N);
    for (int i = 0; i < N; i++) cin >> H[i];
    long long T = 0;
    for (int i = 0; i < N; i++) {
        // Calculate the number of full cycles (3 attacks dealing 5 damage)
        long long cycles = H[i] / 5;
        T += cycles * 3;
        long long remaining = H[i] % 5;
        if (remaining == 0) continue;
        // The next attack is at T+1
        if (remaining <= 1) {
            T += 1;
        } else if (remaining <= 3) {
            T += 2;
        } else { // remaining is 4
            T += 3;
        }
    }
    cout << T << endl;
    return 0;
}