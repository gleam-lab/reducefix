#include <iostream>
#include <vector>
using namespace std;

int main() {
    int N;
    cin >> N;
    vector<long long> H(N);
    for (int i = 0; i < N; i++) {
        cin >> H[i];
    }

    long long T = 0;
    int front = 0; // index of the first enemy with health > 0

    while (front < N) {
        T++;
        // Determine damage: 3 if T is multiple of 3, else 1
        long long damage = (T % 3 == 0) ? 3 : 1;
        
        // Attack the frontmost enemy
        H[front] -= damage;
        
        // If this enemy's health drops to 0 or below, move to next
        while (front < N && H[front] <= 0) {
            front++;
        }
    }

    cout << T << endl;
    return 0;
}