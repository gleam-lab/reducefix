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
    int enemy_index = 0;

    while (enemy_index < N) {
        T++;
        // Skip enemies that are already defeated
        while (enemy_index < N && H[enemy_index] <= 0) {
            enemy_index++;
        }
        
        if (enemy_index >= N) break;
        
        // Attack the frontmost alive enemy
        if (T % 3 == 0) {
            H[enemy_index] -= 3;
        } else {
            H[enemy_index] -= 1;
        }
    }

    cout << T << endl;
    return 0;
}