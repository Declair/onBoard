
/* 大侦探福尔摩斯接到一张奇怪的字条：“我们约会吧！ 3485djDkxh4hhGE 2984akDfkkkkggEdsb s&hgsfdk d&Hyscvnm”。大侦探很
 * 快就明白了，字条上奇怪的乱码实际上就是约会的时间“星期四 14:04”，因为前面两字符串中第1对相同的大写英文字母（大小写有区分）是
 * 第4个字母'D'，代表星期四；第2对相同的字符是'E'，那是第5个英文字母，代表一天里的第14个钟头（于是一天的0点到23点由数字0到9、
 * 以及大写字母A到N表示）；后面两字符串第1对相同的英文字母's'出现在第4个位置（从0开始计数）上，代表第4分钟。现给定两对字符串，
 * 请帮助福尔摩斯解码得到约会的时间。 
 *  
 * 输入描述:
 * 输入在4行中分别给出4个非空、不包含空格、且长度不超过60的字符串。
 * 
 * 输出描述:
 * 在一行中输出约会的时间，格式为“DAY HH:MM”，其中“DAY”是某星期的3字符缩写，即MON表示星期一，TUE表示星期二，WED表示星期三，THU表示星期
 * 四，FRI表示星期五，SAT表示星期六，SUN表示星期日。题目输入保证每个测试存在唯一解。
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
