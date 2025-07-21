#include <iostream>
#include <vector>
using namespace std;

int main() {
    int N;
    cin >> N;
    vector<int> healths(N);
    for (int &h : healths) {
        cin >> h;
    }

    long long T = 0;
    for (int health : healths) {
        T += (health + 2) / 3; // This is equivalent to ceil(health / 3)
        // If health % 3 == 2, we can subtract 3 first if T is a multiple of 3
        T -= (health % 3 == 2) ? 1 : 0;
    }

    cout << T << endl;
    return 0;
}