
//一只袋鼠要从河这边跳到河对岸，河很宽，但是河中间打了很多桩子，每隔一米就有一个，每个桩子上都
//有一个弹簧，袋鼠跳到弹簧上就可以跳的更远。每个弹簧力量不同，用一个数字代表它的力量，如果弹簧
//力量为5，就代表袋鼠下一跳最多能够跳5米，如果为0，就会陷进去无法继续跳跃。河流一共N米宽，袋
//鼠初始位置就在第一个弹簧上面，要跳到最后一个弹簧之后就算过河了，给定每个弹簧的力量，求袋鼠最
//少需要多少跳能够到达对岸。如果无法到达输出-1
#include<iostream>
using namespace std;
int main()
{
    int N, i, j, temp_;
    int a[10002];
    int best[10002];	//动态规划，在该点的最少跳跃次数 
    int fail=10005;		
    cin>>N;
    for(i=1;i<N+1;i++) {
    	cin>>a[i];
	}
	best[N]=0;
	for(j=N-1;j>0;j--) {
		best[j]=fail;
		temp_=fail;
		for(i=a[j];i>0;i--) {
			if(j+i>=N) {
				best[j]=1;
				break;
			}
			else {
				temp_=best[j+i]+1;
			}
			if(temp_<best[j])
				best[j]=temp_;
		} 
	}
	cout<<best[1];
    return 0;
}
