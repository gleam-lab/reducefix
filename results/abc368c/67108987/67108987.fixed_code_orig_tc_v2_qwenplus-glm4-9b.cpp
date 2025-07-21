#include <iostream>
#include <vector>

using namespace std;

int main() {
    int N;
    cin >> N;
    vector<int> H(N);
    for (int i = 0; i < N; i++) cin >> H[i];
    
    long long total_health = 0;
    for (int i = 0; i < N; i++) {
        total_health += H[i];
    }
    
    long long total_attacks = total_health;
    long long remainder = total_attacks % 3;
    
    if (remainder == 0) {
        cout << total_attacks << endl;
    } else {
        cout << total_attacks + (3 - remainder) << endl;
    }
    
    return 0;
}