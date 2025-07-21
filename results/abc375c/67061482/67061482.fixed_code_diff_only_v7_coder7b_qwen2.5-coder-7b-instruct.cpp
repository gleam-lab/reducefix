#include <bits/stdc++.h>
using namespace std;

int main() {
    double a, b, c, d, cou;
    int N;
    cin >> N;
    a = 0;
    b = 0;
    cou = 0;
    for(int i = 0; i < N; i++) {
        cin >> c >> d;
        cou += sqrt(pow(c-a, 2) + pow(d-b, 2)); // Corrected calculation of distance
        a = c;
        b = d;
    }
    cou += sqrt(pow(a, 2) + pow(b, 2)); // Corrected return path distance calculation
    cout << cou << endl;
}