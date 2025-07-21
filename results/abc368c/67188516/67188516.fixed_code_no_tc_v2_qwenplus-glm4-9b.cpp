#include <iostream>
#include <vector>

using namespace std;

int main() {
    int N;
    cin >> N;
    vector<int> health(N);
    long long T = 0;
    
    for (int i = 0; i < N; ++i) {
        cin >> health[i];
        // Calculate the minimum number of attacks needed for this enemy
        T += (health[i] + 2) / 3; // This is equivalent to ceil(health[i] / 3)
    }
    
    cout << T << endl;
    
    return 0;
}