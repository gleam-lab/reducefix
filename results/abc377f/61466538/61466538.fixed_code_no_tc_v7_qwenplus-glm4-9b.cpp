#include <iostream>
using namespace std;

long long n, m;
long long a[1001], b[1001];

// Function to check if a given position can be attacked by any of the existing pieces
bool canAttack(long long x, long long y) {
    for (long long i = 0; i < m; ++i) {
        long long dx = abs(a[i] - x);
        long long dy = abs(b[i] - y);
        if (dx == dy || dx == n - dy || dy == n - dx) {
            return true;
        }
    }
    return false;
}

int main() {
    cin >> n >> m;
    long long total = n * n;
    for (long long i = 0; i < m; ++i) {
        cin >> a[i] >> b[i];
        // Subtracting the positions that are already occupied or cannot be occupied
        total--;
        if (!canAttack(a[i], b[i])) {
            total--; // Subtracting the positions that are under attack
        }
    }
    cout << total << endl;
    return 0;
}