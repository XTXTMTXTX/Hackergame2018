#include<cstdio>
#include<cstdlib>
#include<cstring>
#define ll long long
using namespace std;
const ll table[20][12]={{0,8,7,6,5,8,3,9,2,3,4,6},
						{0,0,2,5,2,9,4,9,4,2,9,4},
						{0,8,5,3,8,3,6,8,7,6,7,6},
						{0,0,8,8,9,3,2,7,9,4,6,9},
						{0,8,8,8,7,5,2,3,2,4,9,3},
						{0,0,4,4,7,8,8,6,9,6,4,5},
						{0,8,5,6,9,5,3,6,4,8,4,3},
						{0,0,7,6,3,6,5,5,6,8,8,7},
						{0,8,7,7,4,5,4,5,3,9,7,7},
						{0,0,5,3,7,4,8,4,3,5,4,6},
						{0,8,5,7,2,9,4,4,3,7,6,2},
						{0,0,2,2,3,9,4,5,2,8,7,9},
						{0,8,6,6,7,8,3,3,6,4,8,2},
						{0,0,7,6,4,2,8,9,4,4,5,6},
						{0,8,9,3,8,5,6,5,7,8,9,2},
						{0,0,8,9,3,7,2,9,9,4,7,2},
						{0,8,2,8,8,7,2,7,6,4,5,4},
						{0,0,2,7,5,2,7,8,3,7,2,4},
						{0,8,9,5,7,2,5,2,4,5,2,5},
						{0,0,9,8,4,6,4,2,8,5,8,9}};
const char BASEtable[64]={65,66,67,68,69,70,71,72,73,74,75,76,
						77,78,79,80,81,82,83,84,85,86,87,88,
						89,90,97,98,99,100,101,102,103,104,
						105,106,107,108,109,110,111,112,113,
						114,115,116,117,118,119,120,121,122,
						48,49,50,51,52,53,54,55,56,57,'-','_'
						};
char BASEreftable[256],tmp;
ll ans[]={2,6,8,8,3,5,5,7,4,9},innum[10];
int main() {
	for(int i=0;i<64;i++)BASEreftable[BASEtable[i]]=i;
	for(int i=0;i<10;i++){
		scanf("%c",&tmp);
		innum[i]=BASEreftable[tmp]-ans[i];
	}
	for(int i=0;i<10;i++){
		for(int j=0;j<10;j++)if(j!=0)printf("%d ",table[j*2][i+2]+table[j*2][1]*table[j*2+1][i+2]);else	printf("%d ",innum[i]);
		printf("\n");
	}
}
