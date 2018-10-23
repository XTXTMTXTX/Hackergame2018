#include<cstdio>
#include<cstring>
#include<cstdlib>
using namespace std;
char inp[1024],fc,sinp[1024],cinp[1024],finp[1024],ginp[1024],rinp[1024],linp[1024];
int main(){
	freopen("typed_printf.cpp","r",stdin);
	freopen("typed_printf_ans.cpp","w",stdout);
	for(int i=0;i<134;i++){
		gets(inp);
		fc=inp[0];
		strncpy(sinp,inp+1,6);
		sinp[6]='\0';
		strncpy(cinp,inp+8,12);
		cinp[12]='\0';
		strncpy(finp,inp+20,2);
		finp[2]='\0';
		strncpy(ginp,inp+22,10);
		ginp[10]='\0';
		strncpy(rinp,inp+32,7);
		rinp[7]='\0';
		strcpy(linp,inp+39);
		printf("%c%s%s%s%s%s%s\n",fc,rinp,sinp,finp,cinp,ginp,linp);
		
	}
	
	return 0;
}
