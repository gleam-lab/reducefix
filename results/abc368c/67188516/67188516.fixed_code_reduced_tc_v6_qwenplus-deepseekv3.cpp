#include <iostream>
#include <vector>

using namespace std;

int main() {
    int N;
    cin >> N;
    vector<long long> H(N);
    for (int i = 0; i < N; ++i) {
        cin >> H[i];
    }

    long long T = 0;
    long long pos = 0; // 0, 1, 2 indicating the position in the attack cycle (0: first attack, 1: second, 2: third)

    for (int i = 0; i < N; ++i) {
        long long health = H[i];
        long long full_cycles = health / 5;
        T += full_cycles * 3;
        health %= 5;
        
        if (health == 0) continue;
        
        if (pos == 0) {
            if (health <= 1) {
                T += 1;
                pos = 1;
            } else if (health <= 2) {
                T += 2;
                pos = 2;
            } else if (health <= 5) {
                T += 3;
                pos = 0;
            }
        } else if (pos == 1) {
            if (health <= 1) {
                T += 1;
                pos = 2;
            } else if (health <= 4) {
                T += 2;
                pos = 0;
            }
        } else if (pos == 2) {
            if (health <= 3) {
                T += 1;
                pos = 0;
            } else {
                T += 2;
                pos = 1;
            }
        }
    }

    cout << T << endl;
    return 0;
}