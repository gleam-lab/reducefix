#include <iostream>
#include <vector>
using namespace std;

int main() {
  int N;
  cin >> N;
  vector<int> H(N);
  for(int i = 0; i < N; i++)
    cin >> H[i];

  long long T = 0;
  while(true) {
    bool done = true;
    for(int i = 0; i < N; i++) {
      if(H[i] > 0) {
        done = false;
        if((T + 1) % 3 == 0)
          H[i] -= 3;
        else
          H[i] -= 1;
        T++;
      }
    }
    if(done) break;
  }

  cout << T << endl;
}