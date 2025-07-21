#include<bits/stdc++.h>

using namespace std;

int main() {
    int N;
    cin >> N;
    vector<int> H(N);
    for (int i = 0; i < N; i++) cin >> H[i];
    long long T = 0;

    for (int health : H) {
        if (health % 3 == 0) {
            T += health / 3;
        } else if (health % 3 == 1) {
            T += (health - 1) / 3;
            T += 2;
        } else { // health % 3 == 2
            T += health / 3;
            T += 1;
        }
    }
    
    cout << T << endl;
    return 0;
}