// SeeAlso: 

#include <bits/stdc++.h>

using namespace std;

typedef long long ll;
typedef vector<int> vi;
typedef vector<ll> vl;
typedef pair<int,int> pii;
typedef pair<ll,ll> pll;

#define MAX 100000

typedef int _loop_int;
#define REP(i,n) for(int i = 0; i < n; i++)
#define FOR(i,a,b) for(_loop_int i=(_loop_int)(a);i<(_loop_int)(b);++i)
#define FORR(i,a,b) for(_loop_int i=(_loop_int)(b)-1;i>=(_loop_int)(a);--i)

#define DEBUG(x) cout<<#x<<": "<<x<<endl
#define DEBUG_VEC(v) cout<<#v<<":";REP(i,v.size())cout<<" "<<v[i];cout<<endl
#define ALL(a) (a).begin(),(a).end()

#define CHMIN(a,b) a=min((a),(b))
#define CHMAX(a,b) a=max((a),(b))

int N, Q;
string S;
int l[MAX], r[MAX];

int t[MAX];

int main() {
    cin >> N >> Q;
    cin >> S;

    t[0] = 0;
    for(int i = 1; i < N; i++) {
        if(S[i] == 'C') {
            if(S[i-1]=='A') {
                t[i] = t[i-1]+1;
            }else{
                t[i] = t[i-1];
            }
        }else{
            t[i] = t[i-1];
        }
    }

    REP(i, Q) {
        cin >> l[i] >> r[i]; 
    }

    REP(i, Q) {
        int ans = t[(r[i]-1)] - t[(l[i]-1)];    
        cout << ans << endl;
    }
    return 0;
}
