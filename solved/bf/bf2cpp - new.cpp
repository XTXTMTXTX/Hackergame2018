#include<cstdio>
#include<cstdlib>
#include<cstring>
using namespace std;
char ch;
int count;
int ptr=0;
int main() {
	freopen("bf.txt","r",stdin);
	freopen("bfcpp.cpp","w",stdout);
	ch=getchar();
	while(ch!=EOF){
		if(ch=='>'||ch=='<'||ch=='-'||ch=='+'||ch=='.'||ch==','||ch=='['||ch==']'){
			if(ch=='.'){
				printf("printf(\"%%d \",(st[%d]%%256+256)%%256);\n",ptr);
			}
			if(ch==','){
				printf("scanf(\"%%d\",&st[%d]);\n",ptr);
			}
			if(ch=='['){
				printf("while (st[%d]) {\n",ptr);
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
				printf("st[%d]+=%d;\n",ptr,count);
				continue;
			}
			if(ch=='-'){
				count=1;
				ch=getchar();
				while(ch!=EOF&&ch!='>'&&ch!='+'&&ch!='<'&&ch!='.'&&ch!=','&&ch!='['&&ch!=']'){
					if(ch=='-')count++;
					ch=getchar();
				}
				printf("st[%d]-=%d;\n",ptr,count);
				continue;
			}
		}
		ch=getchar();
	}
}
