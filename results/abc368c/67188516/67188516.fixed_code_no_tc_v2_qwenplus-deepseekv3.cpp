#include <iostream>
#include <vector>
using namespace std;

int main() {
    int N;
    cin >> N;
    vector<long long> H(N);
    for (int i = 0; i < N; ++i) {
        cin >> H[i];
    }
    
    long long ans = 0;
    long long pos = 0; // T % 3. T starts at 0, first attack is T=1.
    
    for (int i = 0; i < N; ++i) {
        long long h = H[i];
        long long cycles = h / 5;
        ans += cycles * 3;
        long long rem = h % 5;
        
        if (rem == 0) continue;
        
        if (pos == 0) {
            if (rem <= 2) {
                ans += rem;
                pos += rem;
            } else {
                ans += 3;
                pos = 0;
            }
        } else if (pos == 1) {
            if (rem == 1) {
                ans += 1;
                pos = 2;
            } else if (rem == 2) {
                ans += 2;
                pos = 0;
            } else if (rem == 3) {
                ans += 2;
                pos = 2;
            } else if (rem == 4) {
                ans += 3;
                pos = 1;
            }
        } else if (pos == 2) {
            if (rem == 1) {
                ans += 1;
                pos = 0;
            } else if (rem == 2) {
                ans += 2;
                pos = 1;
            } else if (rem == 3) {
                ans += 1;
                pos = 0;
            } else if (rem == 4) {
                ans += 2;
                pos = 0;
            }
        }
        pos %= 3;
    }
    
    cout << ans << endl;
    return 0;
}