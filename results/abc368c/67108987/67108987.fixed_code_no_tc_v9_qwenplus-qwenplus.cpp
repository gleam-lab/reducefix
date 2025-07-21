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
    long long carry = 0; // This will simulate the attacks on future enemies

    for (int i = 0; i < N; ++i) {
        long long h = H[i];

        // Subtract the carried over damage from previous attacks
        if (carry > 0) {
            // carry is the number of attacks at this point
            long long damage = 0;
            if (carry <= h / 2) {
                damage = carry * 2;
                h -= damage;
                T += carry * 2;
                carry = 0;
            } else {
                h -= carry * 2;
                T += carry * 2;
                carry = 0;
                if (h < 0) h = 0;
            }
        }

        while (h > 0) {
            T++;
            carry++;
            if (T % 3 == 0) {
                h -= 3;
            } else {
                h -= 1;
            }
        }

        // Distribute remaining attacks to next enemies
        if (carry > 0) {
            // Each enemy after this one can receive carry attacks
            // We don't process them now, just pass the carry forward
        }
    }

    cout << T << endl;
    return 0;
}