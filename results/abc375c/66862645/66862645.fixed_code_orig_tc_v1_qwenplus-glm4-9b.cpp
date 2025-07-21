#include <iostream>
#include <cmath>

using namespace std;

int main() {
    long long N, X, Y;
    long long prevX = 0, prevY = 0;
    long long ans = 0.0;

    cin >> N;

    for (int i = 0; i < N; i++) {
        cin >> X >> Y;
        ans += sqrt(pow(X - prevX, 2) + pow(Y - prevY, 2));
        prevX = X, prevY = Y;
    }
    ans += sqrt(pow(X - prevX, 2) + pow(Y - prevY, 2));  // Return to origin

    cout << fixed << setprecision(6) << ans << endl;

    return 0;
}