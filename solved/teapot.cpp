#include<cstdio>
#include<cstdlib>
#include<winsock2.h>
#include<windows.h>
void SendHtmlData() {
	struct hostent *p_hostent = gethostbyname("202.38.95.46");
	if(p_hostent == NULL) {
		printf("ERROR\n");
		return;
	}
	sockaddr_in addr_server;
	addr_server.sin_family = AF_INET;
	addr_server.sin_port = htons(12005);
	memcpy(&(addr_server.sin_addr),p_hostent->h_addr_list[0],sizeof(addr_server.sin_addr));
	int sock = socket(AF_INET,SOCK_STREAM,IPPROTO_TCP);
	int res = connect(sock,(sockaddr*)&addr_server,sizeof(addr_server));
	if(res == -1) {
		printf("ERROR\n");
		closesocket(sock);
		return;
	}
	char sendData[4100];
	sprintf(sendData,"BREW http://202.38.95.46:12005/the_super_great_hidden_url_for_brewing_tea/black_tea HTTP/1.1\r\n\
Host: 202.38.95.46:12005\r\n\
Content-Type: message/teapot\r\n\
Upgrade-Insecure-Requests: 1\r\n\r\n");
	send(sock,sendData,4096,0);
	char m_readBuffer[4096];
	char* Buffer;
	FILE *fp;
	
	fp=fopen("111.html","wb");
	int readCount = recv(sock,m_readBuffer, 4096,0),iSize=0,oSize=0;
	for(int i=0;i<readCount;i++)fputc(m_readBuffer[i],fp);
	readCount = recv(sock,m_readBuffer, 4096,0),iSize=0,oSize=0;
	for(int i=0;i<readCount;i++)fputc(m_readBuffer[i],fp);
	fclose(fp);
	closesocket(sock);
}
int main() {
	WSADATA wsadata; 
	if(WSAStartup(MAKEWORD(1,1),&wsadata)!=0) {
		printf("wsastartup() failed!!\n");
		return 0;
	}
	SendHtmlData();
	WSACleanup();
	return 0;
}
