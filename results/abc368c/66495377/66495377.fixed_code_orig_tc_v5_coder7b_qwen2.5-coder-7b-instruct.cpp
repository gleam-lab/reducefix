#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

long long num_attack(long long t, long long h) {
    long long cnt = 0;
    while (h > 0) {
        t++;
        if (t % 3 == 0) {
            h -= 3;
        } else {
            h -= 1;
        }
        cnt++;
    }
    return cnt;
}

int main() {
    int n;
    cin >> n;
    vector<long long> h(n);
    for (int i = 0; i < n; ++i) {
        cin >> h[i];
    }

    long long total_attacks = 0;
    for (int i = 0; i < n; ++i) {
        total_attacks += num_attack(total_attacks, h[i]);
    }

    cout << total_attacks << endl;
}