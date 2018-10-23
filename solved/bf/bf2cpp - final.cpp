#include<cstdio>
#include<cstdlib>
#include<cstring>
using namespace std;
char ch;
int count;
int ptr=0;
long long st[12];
int main() {
	freopen("bf.txt","r",stdin);
	freopen("bfcpp.txt","w",stdout);
	ch=getchar();
	while(ch!=EOF){
		if(ch=='>'||ch=='<'||ch=='-'||ch=='+'||ch=='.'||ch==','||ch=='['||ch==']'){
			if(ch=='.'){
				//printf("printf(\"%%d \",(st[%d]%%256+256)%%256);\n",ptr);
			}
			if(ch==','){
				//printf("scanf(\"%%d\",&st[%d]);\n",ptr);
			}
			if(ch==']'){
				for(int i=0;i<=ptr;i++)printf("0 ");
				for(int i=ptr+1;i<12;i++)printf("%d ",st[i]);
				printf("\n");
			}
			if(ch=='>'){
				count=1;
				ch=getchar();
				while(ch!=EOF&&ch!='<'&&ch!='-'&&ch!='+'&&ch!='.'&&ch!=','&&ch!='['&&ch!=']'){
					if(ch=='>')count++;
					ch=getchar();
				}
				ptr+=count;
				continue;
			}
			if(ch=='<'){
				count=1;
				ch=getchar();
				while(ch!=EOF&&ch!='>'&&ch!='-'&&ch!='+'&&ch!='.'&&ch!=','&&ch!='['&&ch!=']'){
					if(ch=='<')count++;
					ch=getchar();
				}
				ptr-=count;
				continue;
			}
			if(ch=='+'){
				count=1;
				ch=getchar();
				while(ch!=EOF&&ch!='>'&&ch!='-'&&ch!='<'&&ch!='.'&&ch!=','&&ch!='['&&ch!=']'){
					if(ch=='+')count++;
					ch=getchar();
				}
				st[ptr]=count;
				continue;
			}
			if(ch=='-'){
				count=1;
				ch=getchar();
				while(ch!=EOF&&ch!='>'&&ch!='+'&&ch!='<'&&ch!='.'&&ch!=','&&ch!='['&&ch!=']'){
					if(ch=='-')count++;
					ch=getchar();
				}
				//printf("st[%d]-=%d;\n",ptr,count);
				printf("%d\n",ptr);
				continue;
			}
		}
		ch=getchar();
	}
}
