// SeeAlso: https://atcoder.jp/contests/abc124/tasks/abc124_c

#include <iostream>
#include <iomanip>
#include <algorithm>
#include <cmath>
#include <limits>

#define MAX 4

typedef int _loop_int;
#define REP(i,n) for(int i = 0; i < n; i++)
#define FOR(i,a,b) for(_loop_int i=(_loop_int)(a);i<(_loop_int)(b);++i)
#define FORR(i,a,b) for(_loop_int i=(_loop_int)(b)-1;i>=(_loop_int)(a);--i)

#define DEBUG(x) cout<<#x<<": "<<x<<endl
#define DEBUG_VEC(v) cout<<#v<<":";REP(i,v.size())cout<<" "<<v[i];cout<<endl
#define ALL(a) (a).begin(),(a).end()

#define CHMIN(a,b) a=min((a),(b))
#define CHMAX(a,b) a=max((a),(b))

using namespace std;

int main() {
    string S;

    cin >> S;

    int a = 0;
    int b = 0;

    REP(i, S.size()) {
        string x;
        if ((i % 2) == 0) {
            x = "0";
        } else {
            x = "1";
        }

        if (S.substr(i, 1) != x) {
            a++;
        }
    }

    REP(i, S.size()) {
        string x;
        if ((i % 2) == 0) {
            x = "1";
        } else {
            x = "0";
        }

        if (S.substr(i, 1) != x) {
            b++;
        }
    }

    cout << min(a, b) << endl;

    return 0;
}
