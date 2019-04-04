// SeeAlso: https://atcoder.jp/contests/abc104/tasks/abc104_c

#include <bits/stdc++.h>

#define MAX 10
#define rep(i,n) for(int i = 0; i < n; i++)

const int INF = 1e9;

using namespace std;

int main() {
    int D, G;
    int p[MAX], c[MAX];
    int ans = INF;
    cin >> D >> G;

    rep(i, D) {
        cin >> p[i] >> c[i];
    }

    cout << ans << endl;
    
    return 0;
}
