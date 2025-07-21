#include <iostream>
#include <vector>

using namespace std;

int main() {
    int N;
    cin >> N;
    vector<int> H(N);
    for (int i = 0; i < N; ++i) cin >> H[i];
    
    long long T = 0;
    for (int health : H) {
        while (health > 0) {
            if (T % 3 == 0) {
                health -= 3;
            } else {
                health -= 1;
            }
            T++;
        }
    }
    
    cout << T << endl;
    return 0;
}