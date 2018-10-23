#include<bits/stdc++.h>
using namespace std;
typedef long long Int;
const int Maxn=102;
int n,M;
int a[Maxn][Maxn];
int det()
{
    int ret=1%M;
    for(int i=1;i<=n;i++)
    {
        int cs=-1;
        for(int j=i;j<=n;j++)
        {
            if(a[j][i]){cs=j;break;}
        }
        if(cs==-1)return 0;
        if(cs!=i)
        {
            for(int j=i;j<=n;j++)swap(a[cs][j],a[i][j]);
            ret=(M-ret)%M;
        }
        for(int j=i+1;j<=n;j++)
        {
            while(a[j][i])
            {
                int mul=a[i][i]/a[j][i];
                for(int k=i;k<=n;k++)a[i][k]=((a[i][k]-(Int)a[j][k]*mul)%M+M)%M;
                for(int k=i;k<=n;k++)swap(a[i][k],a[j][k]);
                ret=(M-ret)%M;
            }
        }
        ret=ret*(Int)a[i][i]%M;
    }
    return ret;
}
int main()
{
    while(scanf("%d%d",&n,&M)!=EOF)
    {
        for(int i=1;i<=n;i++)
            for(int j=1;j<=n;j++)
                scanf("%d",&a[i][j]),a[i][j]%=M;
        printf("%d\n",det());
    }
}
