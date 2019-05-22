// SeeAlso: https://atcoder.jp/contests/abc126/tasks/abc126_a

#include <iostream>
#include <iomanip>
#include <algorithm>
#include <cmath>
#include <limits>
#include <string>

#define MAX 50
#define rep(i,n) for(int i = 0; i < n; i++)

using namespace std;

int N, K;
char S[MAX];

int main() {
    
    cin >> N >> K;
    rep(i, N) {
        cin >> S[i];
    }
    
    for(int i = 0; i < N; i++){
        if (i == (K-1)) {
            S[i] = towlower(S[i]);
        }
    }

    cout << S << endl;

    return 0;
}
