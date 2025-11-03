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
    int front = 0; // index of the first enemy with health > 0

    while (front < N) {
        T++;
        // Attack the frontmost enemy with health > 0
        if (T % 3 == 0) {
            H[front] -= 3;
        } else {
            H[front]--;
        }
        
        // If current enemy's health drops to 0 or below, move to next enemy
        if (H[front] <= 0) {
            front++;
        }
    }

    cout << T << endl;
    return 0;
}