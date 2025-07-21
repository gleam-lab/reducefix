#include <iostream>
#include <vector>
using namespace std;

int main() {
    int N;
    cin >> N;
    vector<int> H(N);
    for (int i = 0; i < N; i++) {
        cin >> H[i];
    }
    
    long long T = 0;
    for (int i = 0; i < N; i++) {
        // Calculate the number of turns needed to defeat the enemy
        long long health = H[i];
        while (health > 0) {
            if (T % 3 == 0) {
                health -= 3;
            } else if (T % 3 == 1) {
                health -= 1;
            } else {
                health -= 2;
            }
            T++;
        }
    }
    cout << T << endl;
    
    return 0;
}