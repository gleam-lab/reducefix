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
        // Calculate the number of attacks needed for this enemy
        ll attacks = H[i];
        while (attacks > 0)
        {
            T++;
            if (T % 3 == 0)
            {
                attacks -= 3;
            }
            else
            {
                attacks--;
            }
        }
    }
    cout << T << endl;
}