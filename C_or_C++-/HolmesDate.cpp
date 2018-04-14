
/* ����̽����Ħ˹�ӵ�һ����ֵ�������������Լ��ɣ� 3485djDkxh4hhGE 2984akDfkkkkggEdsb s&hgsfdk d&Hyscvnm��������̽��
 * ��������ˣ���������ֵ�����ʵ���Ͼ���Լ���ʱ�䡰������ 14:04������Ϊǰ�����ַ����е�1����ͬ�Ĵ�дӢ����ĸ����Сд�����֣���
 * ��4����ĸ'D'�����������ģ���2����ͬ���ַ���'E'�����ǵ�5��Ӣ����ĸ������һ����ĵ�14����ͷ������һ���0�㵽23��������0��9��
 * �Լ���д��ĸA��N��ʾ�����������ַ�����1����ͬ��Ӣ����ĸ's'�����ڵ�4��λ�ã���0��ʼ�������ϣ������4���ӡ��ָ��������ַ�����
 * ���������Ħ˹����õ�Լ���ʱ�䡣 
 *  
 * ��������:
 * ������4���зֱ����4���ǿա��������ո��ҳ��Ȳ�����60���ַ�����
 * 
 * �������:
 * ��һ�������Լ���ʱ�䣬��ʽΪ��DAY HH:MM�������С�DAY����ĳ���ڵ�3�ַ���д����MON��ʾ����һ��TUE��ʾ���ڶ���WED��ʾ��������THU��ʾ����
 * �ģ�FRI��ʾ�����壬SAT��ʾ��������SUN��ʾ�����ա���Ŀ���뱣֤ÿ�����Դ���Ψһ�⡣
 */ 
 
#include<iostream>
#include<string.h>
using namespace std;
void printTime(int x, int b) {
    if(x<10) {
        cout<<"0"<<x<<":";
    }
    else cout<<x<<":";
    if(b<10) {
        cout<<"0"<<b;
    }
    else cout<<b;
}
void printDay(int x) {
    char a[10][7]={"MON", "TUE", "WED", "THU", "FRI", "SAT", "SUN"};
    cout<<a[x]<<" ";
}
bool isBig(char c) {
    if(c>='A' && c<='Z') {
        return true;
    }
    return false;
}
bool is2(char c) {
	if((c>='A' && c<='N')||(c>='0'&&c<='9')) {
        return true;
    }
    return false;
}
bool isEnglish(char c) {
	if((c>='A' && c<='Z')||(c>='a'&&c<='z')) {
        return true;
    }
    return false;
}
int main() {
    char a1[66], a2[66], a3[66], a4[66];
    int i,j,k;
    bool flag;
    cin>>a1;
    cin>>a2;
    cin>>a3;
    cin>>a4;
    flag=false;
    for(i=0;i<strlen(a1);i++) {
        for(j=0;j<strlen(a2);j++) {
            if(a1[i]==a2[j] && isBig(a1[i]) && isBig(a2[j])) {
                flag=true;
                break;
            }
        }
        if(flag) break;
	}
    k=a1[i]-'A';
    printDay(k);
    i++;
    j++;
    k=j;
    flag=false;
    for(;i<strlen(a1);i++) {
    	for(j=k;j<strlen(a2);j++) {
            if(a1[i]==a2[j] && is2(a1[i]) && is2(a2[j])) {
                flag=true;
                break;
            }
        }
        if(flag) break;
	}
	if(a1[i]>='0'&&a1[i]<='9') {
		k=a1[i]-'0';
	}
	else if(a1[i]>='A'&&a1[i]<='N') {
		k=a1[i]-'A'+10;
	}
	for(i=0;i<strlen(a3)&&i<strlen(a4);i++) {
		if(a3[i]==a4[i] && isEnglish(a3[i]) && isEnglish(a4[i]))
			break;
	}
	printTime(k,i);
    return 0;
}
