#include<cstdio>
#include<cstring>
#include<Windows.h>
#include<Winuser.h>
#include<cstdlib>
#define BUFFSIZE 1024
using namespace std;
FILE *fp;
char c;
char* aaa=0;
char buffer2[BUFFSIZE],buffer3[BUFFSIZE],buffer[BUFFSIZE],prbuffer[BUFFSIZE],savebuffer[BUFFSIZE];
int main() {
	freopen("debug.txt","w",stdout);
	int flag;
	while(1) {
		Sleep(10);
		flag=0;
		if(fp=fopen("111.txt","r")) {
			while(!feof(fp)) {
				fgets(buffer,BUFFSIZE,fp);
			}
			fclose(fp);
			if(strcmp(buffer,prbuffer)==0) continue;
			printf("->%s\n",buffer);
			strcpy(savebuffer,buffer);
			while(aaa=strstr(buffer,"__import__('time').sleep(")){
				strcpy(buffer3,buffer);
				strcpy(aaa+4,strchr(strchr(buffer3+(aaa-buffer),')')+1,')')+1);
				*(aaa)='N';
				*(aaa+1)='o';
				*(aaa+2)='n';
				*(aaa+3)='e';
			}
			while(aaa=strstr(buffer,"print(")){
				strcpy(buffer3,buffer);
				strcpy(aaa+4,strchr(buffer3+(aaa-buffer),')')+1);
				*(aaa)='N';
				*(aaa+1)='o';
				*(aaa+2)='n';
				*(aaa+3)='e';
			}
			while(aaa=strstr(buffer,"__import__('os').system(")){
				strcpy(buffer3,buffer);
				strcpy(aaa+1,strchr(strchr(buffer3+(aaa-buffer),')')+1,')')+1);
				*(aaa)='2';
			}
			while(aaa=strstr(buffer,"exit(")){
				strcpy(buffer3,buffer);
				strcpy(aaa+1,strchr(buffer3+(aaa-buffer),')')+1);
				*(aaa)='0';
			}
			fp=fopen("111.py","w");
			fprintf(fp,"qqqq = %s\nprint(qqqq)",buffer);
			fclose(fp);
			system("python 111.py > 1.txt");
			fp=fopen("1.txt","r");
			fgets(buffer2,BUFFSIZE,fp);
			fclose(fp);
			printf("->->%s\n",buffer2);
			strcpy(prbuffer,savebuffer);
			if((buffer2[0]>'9'||buffer2[0]<'0')&&buffer2[0]!='-')continue;
			for(int i=0;(buffer2[i]<='9'&&buffer2[i]>='0')||buffer2[i]=='-';i++){
				int tmp=buffer2[i];
				if(tmp=='-')tmp=189;
				keybd_event(tmp,0,0,0);
				keybd_event(tmp,0,KEYEVENTF_KEYUP,0);
			}
			keybd_event(13,0,0,0);
			keybd_event(13,0,KEYEVENTF_KEYUP,0);
		}
	}
	return 0;
}
