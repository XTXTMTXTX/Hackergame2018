#include<cstdio>
#include<cstdlib>
#include<cstring>
using namespace std;
char ch;
int count;
int main() {
	freopen("bf.txt","r",stdin);
	freopen("bfcpp.cpp","w",stdout);
	ch=getchar();
	while(ch!=EOF){
		if(ch=='>'||ch=='<'||ch=='-'||ch=='+'||ch=='.'||ch==','||ch=='['||ch==']'){
			if(ch=='.'){
				printf("printf(\"%%d \",((*ptr)%%256+256)%%256);\n");
			}
			if(ch==','){
				printf("scanf(\"%%d\",ptr);\n");
			}
			if(ch=='['){
				printf("while (*ptr) {\n");
			}
			if(ch==']'){
				printf("}\n");
			}
			if(ch=='>'){
				count=1;
				ch=getchar();
				while(ch!=EOF&&ch!='<'&&ch!='-'&&ch!='+'&&ch!='.'&&ch!=','&&ch!='['&&ch!=']'){
					if(ch=='>')count++;
					ch=getchar();
				}
				printf("ptr+=%d;\n",count);
				continue;
			}
			if(ch=='<'){
				count=1;
				ch=getchar();
				while(ch!=EOF&&ch!='>'&&ch!='-'&&ch!='+'&&ch!='.'&&ch!=','&&ch!='['&&ch!=']'){
					if(ch=='<')count++;
					ch=getchar();
				}
				printf("ptr-=%d;\n",count);
				continue;
			}
			if(ch=='+'){
				count=1;
				ch=getchar();
				while(ch!=EOF&&ch!='>'&&ch!='-'&&ch!='<'&&ch!='.'&&ch!=','&&ch!='['&&ch!=']'){
					if(ch=='+')count++;
					ch=getchar();
				}
				printf("(*ptr)+=%d;\n",count);
				continue;
			}
			if(ch=='-'){
				count=1;
				ch=getchar();
				while(ch!=EOF&&ch!='>'&&ch!='+'&&ch!='<'&&ch!='.'&&ch!=','&&ch!='['&&ch!=']'){
					if(ch=='-')count++;
					ch=getchar();
				}
				printf("(*ptr)-=%d;\n",count);
				continue;
			}
		}
		ch=getchar();
	}
}
