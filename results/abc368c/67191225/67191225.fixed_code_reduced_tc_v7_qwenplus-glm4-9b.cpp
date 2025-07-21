#include <iostream>
#include <vector>
#include <algorithm>

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
        // Reduce the health of the enemy by the largest multiple of 3 possible
        T += H[i] / 3;
        // If there's a remainder, we need to attack more times
        T += (H[i] % 3) != 0;
    }
    
    cout << T << endl;
    return 0;
}