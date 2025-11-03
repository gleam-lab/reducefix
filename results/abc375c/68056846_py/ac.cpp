#include <iostream>
#include <vector>
#include <cmath>

using namespace std;
using ll = long long;
using vl = vector<ll>;

int main() {
ll n;
cin >> n;
vl x(n), y(n);
for (int i = 0; i < n; ++i) {
cin >> x[i] >> y[i];
}

double ans = sqrt((double)(x[0] * x[0] + y[0] * y[0])); 

for (ll i = 1; i < n; ++i) {
ans += sqrt((double)((x[i - 1] - x[i]) * (x[i - 1] - x[i]) + (y[i - 1] - y[i]) * (y[i - 1] - y[i])));
}

ans += sqrt((double)(x[n - 1] * x[n - 1] + y[n - 1] * y[n - 1])); 

cout.precision(17);
cout << fixed << ans << endl;

return 0;
}