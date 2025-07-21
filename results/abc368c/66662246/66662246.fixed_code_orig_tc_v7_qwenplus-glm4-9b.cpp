#include <iostream>
#include <vector>
using namespace std;

long long attack(int health, int T) {
    if (health <= 0) return 0;
    // Total attacks is the ceiling of (health + T - 1) / T
    return (health + T - 1) / T;
}

bool canDefeatAll(vector<int>& H, long long T) {
    long long totalAttacks = 0;
    for (int health : H) {
        totalAttacks += attack(health, T);
    }
    return totalAttacks <= T;
}

int main() {
    int N;
    cin >> N;
    vector<int> H(N);
    for (int i = 0; i < N; ++i) {
        cin >> H[i];
    }
    
    long long left = 0;
    long long right = 1000000000; // We assume T can be up to 1 billion.
    while (left < right) {
        long long mid = left + (right - left) / 2;
        if (canDefeatAll(H, mid)) {
            right = mid;
        } else {
            left = mid + 1;
        }
    }
    cout << left << endl;
    return 0;
}