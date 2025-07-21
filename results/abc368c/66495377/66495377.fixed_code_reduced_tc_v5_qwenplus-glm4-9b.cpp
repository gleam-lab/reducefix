#include <iostream>
#include <vector>

using namespace std;

long long calculate_attacks(int n, const vector<int>& health) {
    long long t = 0, remaining = 0;

    // Calculate the total number of attacks needed
    for (int h : health) {
        remaining += h;
    }

    // Use a binary search to find the minimum value of t
    long long low = 0, high = remaining;
    while (low < high) {
        long long mid = (low + high + 1) / 2;
        long long attacks = 0;
        for (int h : health) {
            attacks += (h + 2 * mid - 1) / (2 * mid); // ceil(h / (2 * mid))
        }
        if (attacks > mid) {
            low = mid;
        } else {
            high = mid - 1;
        }
    }

    return low;
}

int main() {
    int n;
    cin >> n;
    vector<int> health(n);
    for (int i = 0; i < n; ++i) {
        cin >> health[i];
    }
    cout << calculate_attacks(n, health) << endl;
    return 0;
}