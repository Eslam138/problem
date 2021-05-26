
#include<bits/stdc++.h>
#define ll long long
using namespace std;
const ll maxn =1e5+10;
const ll inf=0x3f3f3f3f;
ll rd(){ll t;scanf("%I64d",&t);return t;}
#define en '\n'
#define mem(a,b) memset(a,b,sizeof(a))
#define pb push_back
 
ll k,a,b;
ll A[4][4],B[4][4];
ll vis[4][4];
ll ans[maxn][2];
ll Aw,Bw=0;
ll x,y,xx,yy;
ll run(ll X,ll Y){return ((X==3 and  Y==2) or (X==2 and Y==1) or (X==1 and Y==3));}
ll L,R;
void dfs(ll x,ll y,ll dep){
    vis[x][y]=dep;
    ans[dep][0]=run(x,y);
    ans[dep][1]=run(y,x);
    xx=A[x][y];yy=B[x][y];
    if(vis[xx][yy]){L=vis[xx][yy],R=dep;return ;}
    return dfs(xx,yy,dep+1);
}
signed main() {
    #ifdef swt
    freopen("input2.txt","r",stdin);
    #endif // local
    //#define ll register ll
    cin>>k>>a>>b;
    for(ll i=1;i<=3;i++){
        for(ll j=1;j<=3;j++){
            A[i][j]=rd();
        }
    }
    for(ll i=1;i<=3;i++){
        for(ll j=1;j<=3;j++){
            B[i][j]=rd();
        }
    }
    dfs(a,b,1);
        for(int i=1;i<=min(k,R);i++){
        Aw+=ans[i][0],Bw+=ans[i][1];
        }
    if(k<=R){
        cout<<Aw<<' '<<Bw<<en;return 0;
    }
    k-=R;
    ll T=R-L+1;
    ll AA=0,BB=0;
    for(ll i=L;i<=R;i++){AA+=ans[i][0];BB+=ans[i][1];}
    AA*=k/T;
    BB*=k/T;
    ll yu=k%T;
    for(ll i=L;i<=L+yu-1;i++){
        Aw+=ans[i][0];Bw+=ans[i][1];
    }
    cout<<Aw+AA<<' '<<Bw+BB<<en;
    return 0;
}
/*
10	2	1
1	1	1
1	1	1
1	1	1
2	2	2
2	2	2
2	2	2*/