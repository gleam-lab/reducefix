#include <iostream>
using namespace std;

int main() {
    int N;
    cin >> N;
    vector<int> a(N), b(N-1);

    for (int i = 0; i < N; i++) {
        cin >> a[i];
    }
    for (int i = 0; i < N-1; i++) {
        cin >> b[i];
    }

    // Assuming all toys must fit into one of the N-1 boxes
    bool toyFits = false;
    int x;

    for (int i = 0; i < N-1; i++) {
        if (a[0] <= b[i]) { // Check if the largest toy can fit into box b[i]
            toyFits = true;
            x = b[i]; // If it can, the smallest x is the size of this box
            break;
        }
    }

    if (!toyFits) {
        x = a[0]; // Otherwise, the smallest x is the size of the largest toy
    }

    cout << x << endl;

    return 0;
}