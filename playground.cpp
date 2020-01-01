#include <bits/stdc++.h>

typedef long long ll;


#define MAX 1000000

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

struct Node {
    int parent, left, right;
};

Node tree[MAX];

void rec(int u, int p) {
    
}

int main() {
    int N;
    cin >> N;   

    REP(i, N) {
        tree[i].parent = tree[i].left = tree[i].right = NIL;
    }

    REP(i, N) {
        int a, b;
        cin >> a >> b;
        REP(j, b) {
            int c, l;
            cin >> c; 
            tree[a].parent = NIL;
            if (j==0) {
                tree[a].left = c;
            } else {
                tree[l].right = c;
            }
            l = c;
            tree[c].parent = a;
        } 
    }
    
    int r = 0;
    REP(i, N) {
        if(tree[i].parent==NIL) {
            r=i;
        }
    }

    rec(r, 0);
}
