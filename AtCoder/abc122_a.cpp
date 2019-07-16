// SeeAlso: https://atcoder.jp/contests/abc122/tasks/abc122_a

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

char b;
int main() {
    cin >> b;

    char ans;
    switch (b) {
        case 'A':
            ans = 'T';
            break;
        case 'T':
            ans = 'A';
            break;
        case 'C':
            ans = 'G';
            break;            
        case 'G':
            ans = 'C';
            break;            
    }
        
    cout << ans << endl;

    return 0;
}
