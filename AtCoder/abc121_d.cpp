// SeeAlso: https://atcoder.jp/contests/abc121/tasks/abc121_d

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

ll oddsolve(ll a){
    return (a+1)/2%2;
}
ll solve(ll a){
    if(a%2==1) return oddsolve(a);
    else return oddsolve(a+1)^(a+1);
}
 
int main(void) {
    ll A,B;
    cin>>A>>B;
    cout<<(solve(B)^solve(A-1))<<endl;
}
