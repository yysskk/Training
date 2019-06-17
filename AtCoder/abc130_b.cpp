// SeeAlso: 

#include <bits/stdc++.h>

#define MAX 100
#define rep(i,n) for(int i = 0; i < n; i++)

using namespace std;

int n, x;

int l[MAX];

int main() {


    cin >> n >> x;
    rep(i, n) {
        cin >> l[i];
    }

    int ans = 0;
    int d = 0;
    rep(i, n) {
        ans++;
        d += l[i];

        if (d > x) {
            cout << ans << endl;
            return 0;
            break;
        }
    }

    ans++;
    cout << ans << endl;

    return 0;
}
