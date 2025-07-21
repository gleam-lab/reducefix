#include <iostream>
#include <vector>
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
    // Tracks how many attacks have been made modulo 3
    // 0 means next attack will be a normal attack (1 damage)
    // 1 means next attack will be a normal attack (1 damage)
    // 2 means next attack will be a special attack (3 damage)
    int cycle = 0;

    for (long long h : H) {
        // We simulate attacking this enemy until its health is <= 0
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