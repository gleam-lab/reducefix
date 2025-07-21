#include <iostream>
#include <vector>
using namespace std;

int main() {
    long long n, h;
    cin >> n;
    vector<long long> health(n);
    
    for (int i = 0; i < n; ++i) {
        cin >> h;
        health[i] = h;
    }
    
    long long T = 0;
    while (true) {
        bool all_zero_or_less = true;
        for (long long health_value : health) {
            if (health_value > 0) {
                all_zero_or_less = false;
                break;
            }
        }
        if (all_zero_or_less) break;
        
        for (long long &h : health) {
            h -= (h / T) * T + (1 - (h % T) ? 0 : 1);
        }
        T++;
    }
    
    cout << T << endl;
    return 0;
}