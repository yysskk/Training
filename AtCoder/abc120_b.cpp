// SeeAlso: https://atcoder.jp/contests/abc120/tasks/abc120_b

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

int A,B,K;
int main() {
    cin >> A >> B >> K;

    int m = min(A,B);

    int counter=0;
    
    for(int i=m;i>0;i--) {
        if((A%i)==0 && (B%i)==0) {
            counter++;
        }
        if(counter==K) {
            cout << i << endl;
            break;
        }
    }

    return 0;
}
