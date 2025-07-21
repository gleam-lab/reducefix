#include <iostream>
#include <vector>
using namespace std;

int main() {
    int N;
    cin >> N;
    vector<int> H(N);
    for (int i = 0; i < N; i++) cin >> H[i];
    
    long long T = 0;
    for (int i = 0; i < N; i++) {
        if (H[i] % 3 == 0) {
            T += H[i] / 3;
        } else if (H[i] % 3 == 1) {
            T += (H[i] - 1) / 3 + 1;
        } else { // H[i] % 3 == 2
            T += H[i] / 3;
            T += 2;
        }
    }
    
    cout << T << endl;
    return 0;
}