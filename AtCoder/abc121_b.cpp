// SeeAlso: https://atcoder.jp/contests/abc121/tasks/abc121_b

#include <bits/stdc++.h>

using namespace std;

typedef long long ll;
typedef vector<int> vi;
typedef vector<ll> vl;
typedef pair<int,int> pii;
typedef pair<ll,ll> pll;

#define MAX 20

typedef int _loop_int;
#define REP(i,n) for(int i = 0; i < n; i++)
#define FOR(i,a,b) for(_loop_int i=(_loop_int)(a);i<(_loop_int)(b);++i)
#define FORR(i,a,b) for(_loop_int i=(_loop_int)(b)-1;i>=(_loop_int)(a);--i)

#define DEBUG(x) cout<<#x<<": "<<x<<endl
#define DEBUG_VEC(v) cout<<#v<<":";REP(i,v.size())cout<<" "<<v[i];cout<<endl
#define ALL(a) (a).begin(),(a).end()

#define CHMIN(a,b) a=min((a),(b))
#define CHMAX(a,b) a=max((a),(b))


int N, M, C;
int B[MAX];

int main() {
    cin >> N >> M >> C;

    REP(i, M) {
        cin >> B[i];
    }

    int ans = 0;
    REP(i, N) {
        int temp = C;
        REP(j, M) {
            int a;
            cin >> a;
            temp += B[j] * a;
        }

        if (temp > 0) {

            ans++;
        }
    }

    cout << ans << endl;

    return 0;
}
