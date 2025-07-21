#include <iostream>
using namespace std;

int main() {
    int N;
    cin >> N;
    long long healths[N];
    long long T = 0;
    
    for (int i = 0; i < N; ++i) {
        cin >> healths[i];
    }
    
    for (int i = 0; i < N; ++i) {
        while (healths[i] > 0) {
            if (T % 3 == 0) {
                healths[i] -= 3;
            } else {
                healths[i] -= 1;
            }
            T++;
            if (healths[i] < 0) healths[i] = 0; // Ensure health does not go below zero
        }
    }
    
    cout << T << endl;
    return 0;
}