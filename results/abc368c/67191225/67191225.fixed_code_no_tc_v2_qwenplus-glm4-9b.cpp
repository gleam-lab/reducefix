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
        // Calculate the number of full 3 attacks needed
        T += (H[i] + 2) / 3; // +2 to make sure we can handle the remainder properly
        // Handle any remaining health that is not a multiple of 3
        H[i] -= ((H[i] + 2) / 3) * 3;
    }
    cout << T << endl;
    return 0;
}