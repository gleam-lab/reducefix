#include <iostream>
using namespace std;

int main() {
    int n;
    cin >> n;
    vector<int> health(n);
    
    for (int i = 0; i < n; ++i) {
        cin >> health[i];
    }
    
    long long T = 0;
    for (int i = 0; i < n; ++i) {
        while (health[i] > 0) {
            if (T % 3 == 0) {
                health[i] -= 3;
            } else {
                health[i] -= 1;
            }
            T++;
        }
    }
    
    cout << T << endl;
    return 0;
}