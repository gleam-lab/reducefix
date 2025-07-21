#include<bits/stdc++.h>

using namespace std;

int main() {
    int N;
    cin >> N;
    vector<int> H(N);
    for (int i = 0; i < N; i++) cin >> H[i];
    long long T = 0;

    for (int i = 0; i < N; i++) {
        long long health = H[i];
        while (health > 0) {
            if (T % 3 == 0) {
                if (health >= 3) {
                    health -= 3;
                } else {
                    health = 0;
                }
            } else {
                if (health >= 1) {
                    health -= 1;
                } else {
                    health = 0;
                }
            }
            T++;
        }
    }

    cout << T << endl;
    return 0;
}