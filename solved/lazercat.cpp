#include<cstdio>
#include<cstring>
#include<cstdlib>
using namespace std;
char ch,prevch=0;
int x=0,y=105;
bool map[1000][200];
int main(){
	freopen("seq.txt","r",stdin);
	//freopen("output.txt","w",stdout);
	while(EOF!=(ch=getchar())){
		map[x][y]=1;
		if(prevch!=ch){
			printf("[%3d,%3d]\n",x,y);
			prevch=ch;
		}
		switch(ch){
			case 'U':
				y++;
			break;
			case 'D':
				y--;
			break;
			case 'R':
				x++;
			break;
			case 'L':
				x--;
			break;
		}
	}
	map[x][y]=1;
	freopen("output.txt","w",stdout);
	for(int i=0;i<110;i++){
		for(int j=0;j<520;j++)printf(map[j][109-i]?"¨€":" ");
		printf("\n");
	}
	return 0;
}
