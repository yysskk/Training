// SeeAlso: https://atcoder.jp/contests/abc131/tasks/abc131_a

#include <bits/stdc++.h>

using namespace std;

typedef long long ll;
typedef vector<int> vi;
typedef vector<ll> vl;
typedef pair<int,int> pii;
typedef pair<ll,ll> pll;

#define MAX 100000

typedef int _loop_int;
#define REP(i,n) for(int i = 1; i < n; i++)
#define FOR(i,a,b) for(_loop_int i=(_loop_int)(a);i<(_loop_int)(b);++i)
#define FORR(i,a,b) for(_loop_int i=(_loop_int)(b)-1;i>=(_loop_int)(a);--i)

#define DEBUG(x) cout<<#x<<": "<<x<<endl
#define DEBUG_VEC(v) cout<<#v<<":";REP(i,v.size())cout<<" "<<v[i];cout<<endl
#define ALL(a) (a).begin(),(a).end()

#define CHMIN(a,b) a=min((a),(b))
#define CHMAX(a,b) a=max((a),(b))

string S;

int main() {
    cin >> S;

    bool flag = true;
    REP(i, S.size()) {
        if (S[i] == S[i-1]) {
            flag = false;
            break;
        }
    }

    string ans;
    if (flag) {
        ans = "Good";
    } else {
        ans = "Bad";
    }
    cout << ans << endl;
    return 0;
}


