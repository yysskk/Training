// SeeAlso: https://atcoder.jp/contests/abc125/tasks/abc125_a

#include <bits/stdc++.h>

typedef long long ll;
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

int A, B, T;
int main() {

    cin >> A >> B >> T;

    int ans;
    int temp = (T + 0.5) / A;
    ans = temp * B;
    cout << ans;
    
    return 0;
}
