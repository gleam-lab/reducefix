#include<iostream>
#include<vector>
#include<algorithm>
#include<cmath>
#include<string>
#include<stack>
#include<queue>
#include<set>
#include<map>
#include<numeric>
#include <iomanip>

using namespace std;
using ll = long long;

const double PI = acos(-1.0);

int main()
{
    int N;
    cin >> N;
    vector<ll>H(N);
    for (int i = 0; i < N; i++)
    {
        cin >> H[i];
    }
    ll T = 0;
    for (int i = 0; i < N; i++)
    {
        // Calculate the number of attacks needed for the current enemy
        ll attacks = ceil((double)H[i] / 3.0);
        T += attacks;
        
        // Adjust T based on whether it's a multiple of 3
        if (T % 3 == 0 && H[i] % 3 != 0) {
            T++;
        }
    }
    cout << T << endl;
    return 0;
}