// SeeAlso: 

#include <bits/stdc++.h>

#define MAX 4
#define rep(i,n) for(int i = 0; i < n; i++)

using namespace std;
double W, H;
double x, y;

int main() {

    cin >> W >> H >> x >> y;


    double ans = W * H / 2.0;
    int d;
    if ((x == (W / 2)) && (y == (H/2))) {
        d = 1;
    } else {
        d= 0;
    }
    cout << ans << " "  << d << endl;
    return 0;
}
