#include <bits/stdc++.h>
using namespace std;

int main() {
    ios::sync_with_stdio(false); cin.tie(0); cout.tie(0);

    long long N;
    cin >> N;
    
    vector<long long> X(N + 1), Y(N + 1);
    X[0] = 0, Y[0] = 0;
    for(long long i = 1; i <= N; ++i) cin >> X[i] >> Y[i];

    double result = 0;
    for(long long i = 1; i <= N; ++i) {
        double dx = X[i] - X[i - 1];
        double dy = Y[i] - Y[i - 1];
        result += sqrt(dx * dx + dy * dy);
    }

    cout << fixed << setprecision(15) << result << '\n';

    return 0;
}