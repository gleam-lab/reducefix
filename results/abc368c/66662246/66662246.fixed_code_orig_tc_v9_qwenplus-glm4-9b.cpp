#include <iostream>
#include <vector>

using namespace std;

int main() {
    int n;
    cin >> n;
    vector<int> a(n);
    for (int i = 0; i < n; ++i) {
        cin >> a[i];
    }

    int threeTimes = 0;
    int oneTimes = 0;

    for (int health : a) {
        int timesThree = (health + 2) / 3; // This is equivalent to ceil(health / 3)
        int remainder = health % 3;
        threeTimes += timesThree;
        oneTimes += remainder;
    }

    cout << threeTimes * 3 + oneTimes << endl;

    return 0;
}