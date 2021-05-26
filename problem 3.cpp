
#include<iostream>
#include <algorithm>

using namespace std;

const int maxnum=2e5+5; // to get maximum number of edges
int firstnum[maxnum]; //
int from[maxnum],to[maxnum],cost[maxnum],index[maxnum];
int start[maxnum];int n,m,len;


struct Edges{
    int ta,inde,nxt;
} edges[maxnum];




void addedges (int fir,int ta,int inde,int i)
{
    edges[i].nxt=firstnum[fir];
    firstnum[fir]=i;
    edges[i].ta=ta;
    edges[i].inde=inde;
}

int par[maxnum],num[maxnum];
int fnder (int x)
{
    return par[x]==x?x:par[x]=fnder (par[x]);
}
int dfinedn[maxnum],lower[maxnum],cnt=0;
void dfs (int s,int f) // starting point and array length
{
    dfinedn[s]=lower[s]=++cnt;// assign the start point to be count+1
    for (int p=firstnum[s];p!=0;p=edges[p].nxt){
        int t=edges[p].ta;
        // first of all check if it will make a loop in the graph.
        if (p== ((f-1) ^1) +1) // if will be closed
            continue; // continue avoid the infinite loop
        if (dfinedn[t]==0) // then 
        {
            dfs (t,p);
            if (lower[t]>dfinedn[s]) {
                    start[edges[p].inde]=2;
            }
            else
            {
                lower[s]=min (lower[s],lower[t]); // store the minimum between theses two
            }
        }
        else {
                lower[s]=min (lower[s],dfinedn[t]); //
        }
    }
}
/**
    a function to compare the cost of to indexes
*/
bool cmp (int a,int b)
{
    return cost[a]<cost[b];
}
void unitnum (int c,int d)
{
    if (fnder (c) ==fnder (d))
        return;
    num[fnder (d)]+=num[fnder (c)];
    num[fnder (c)]=0; 
    par[fnder (c)]=fnder (d);
}



int st[maxnum],tail;
/**
    cause we are focusing on minimum tree will use kruskal method to find minimum edge cost.
*/
void kruskal() {
    sort (index,index+m,cmp);
    for (int i=0;i<m&&num[fnder (1)]<n;) {
        int j=i;
        while (cost[index[i]]==cost[index[j]]&&j<m) {
            j ++;
        }
        for (int k=i;k<j;k++) {
            int indk=index[k];
            if (fnder (from[indk])!=fnder (to[indk])) {
                st[tail++]=indk;
                start[indk]=1; // visited
             }
            }
        for (int p=0;p<tail;p++) {
            int tp=st[p];
            int f=fnder (from[tp]), t=fnder (to[tp]);
            addedges(f,t,tp,++len);
            addedges(t,f,tp,++len);
        }
        for (int p=0;p<tail;p++) {
            int tp=st[p];
            int f=fnder (from[tp]), t=fnder (to[tp]);
            dfs (f,0);
            unitnum (f,t);
        }
        cnt=0;
        len=0;
        for (int p=0;p<tail;p++) {
            int tp=st[p];
            int f = fnder(from[tp]);
            int t = fnder(to[tp]);
            firstnum[f]=firstnum[t]=0;
           dfinedn[f]=dfinedn[t]=0;
        }
        i=j;
        tail=0;
    }
}

int main () {
    /*
        check out this
        4 5
        1 2 101
        1 3 100
        2 3 2
        2 4 2
        3 4 1
    */
    cin >> n >> m; // vertices and adjacent
    for (int i=1;i<=n;i++) {
        par[i]=i;
        num[i]=1;
    }
    for (int i=0;i<m;i++) {
        cin >> from[i] ;
        cin >> to[i];
        cin >> cost[i];
        index[i]=i;
    }
    kruskal();
    for (int i=0;i<m;i++) {
        if (start[i]==2)
            cout << "any" << endl;
        else if (start[i]==1)
            cout  << "at least one" << endl;
        else
            cout << "none" << endl;
    }
    return 0;
}
