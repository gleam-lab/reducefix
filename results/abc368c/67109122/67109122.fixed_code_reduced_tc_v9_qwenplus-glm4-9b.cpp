#include <iostream>
#include <vector>

using namespace std;

int main() {
    int N;
    cin >> N;
    vector<int> H(N);
    long long T = 0;
    
    for (int i = 0; i < N; i++) {
        cin >> H[i];
    }
    
    for (int i = 0; i < N; i++) {
        if (H[i] % 3 == 0) {
            T += H[i] / 3;
        } else {
            T += H[i] / 3 + 1;
            H[i] = 3 - H[i] % 3;  // Remaining health after dealing with multiples of 3
        }
        T += H[i];  // Remaining health that needs to be dealt with by decrementing by 1
    }
    
    cout << T << endl;
    return 0;
}