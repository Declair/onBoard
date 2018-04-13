package mains;
/**
* @author Deng
* @version Created at：2018年4月13日 下午10:04:34
* 
*/

/*
 *  有一条彩色宝石项链，是由很多种不同的宝石组成的，包括红宝石，蓝宝石，钻石，翡翠，珍珠等。有
 *一天国王把项链赏赐给了一个学者，并跟他说，你可以带走这条项链，但是王后很喜欢红宝石，蓝宝石，紫
 *水晶，翡翠和钻石这五种，我要你从项链中截取连续的一小段还给我，这一段中必须包含所有的这五种宝
 *石，剩下的部分你可以带走。如果无法找到则一个也无法带走。请帮助学者找出如何切分项链才能够拿到
 *最多的宝石。 
 *输入描述:
 *我们用每种字符代表一种宝石，A表示红宝石，B表示蓝宝石，C代表紫水晶，D代表翡翠，E代表钻石，F代表
 *玉石，G代表玻璃等等，我们用一个全部为大写字母的字符序列表示项链的宝石序列，注意项链是首尾相接的。
 *每行代表一种情况。
 *输出描述:
 *输出学者能够拿到的最多的宝石数量。每行一个
 */
import java.util.Scanner;

public class Necklace {

	public static void main(String[] args) {
		// TODO Auto-generated method stub
		String raw = new String();
		Scanner sb = new Scanner(System.in);
		raw = sb.nextLine();
		boolean AA, BB, CC, DD, EE;
		int length = raw.length();
		int nowl = 0, minl = length;
		for(int i=0; i<length; i++) {
			nowl = 1;
			AA = BB = CC = DD = EE = false;
			for(int j=i;nowl<=length;) {
				if(raw.charAt(j)=='A')
					AA = true;
				else if(raw.charAt(j)=='B')
					BB = true;
				else if(raw.charAt(j)=='C')
					CC = true;
				else if(raw.charAt(j)=='D')
					DD = true;
				else if(raw.charAt(j)=='E')
					EE = true;
				j++;
				j%=length;
				if(AA&&BB&&CC&&DD&&EE)
					break;
				nowl++;
			}
			
			if(nowl<minl) minl=nowl;
		}
		System.out.println(length-minl);
	}

}
