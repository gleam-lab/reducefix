#include<iostream>
#include<vector>

using namespace std;
using ll = long long;

int main()
{
    int N;
    cin >> N;
    vector<ll> H(N);
    for (int i = 0; i < N; i++)
    {
        cin >> H[i];
    }
    
    ll T = 0;
    for (int i = 0; i < N; i++)
    {
        // Process each enemy one by one
        while (H[i] > 0)
        {
            T++;
            if (T % 3 == 0)
            {
                H[i] -= 3;
            }
            else
            {
                H[i] -= 1;
            }
        }
    }
    
    cout << T << endl;
    return 0;
}