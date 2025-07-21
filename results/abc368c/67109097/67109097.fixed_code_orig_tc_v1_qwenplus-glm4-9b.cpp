#include <iostream>
#include <vector>

using namespace std;

int main() {
    int N;
    cin >> N;
    vector<int> H(N);
    for (int i = 0; i < N; i++) cin >> H[i];
    long long T = 0;
    
    // Calculate the total number of attacks needed
    for (int i = 0; i < N; i++) {
        // If health is odd, it needs one extra attack
        T += (H[i] + 1) / 2;
    }
    
    cout << T << endl;
    return 0;
}