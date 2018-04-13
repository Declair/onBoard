package mains;

import java.util.Scanner;

/**
* @author Deng
* @version Created at：2018年4月13日 下午10:06:25
* 
*/

/*
 * 密码要求:
 * 1.长度超过8位
 * 2.包括大小写字母.数字.其它符号,以上四种至少三种
 * 3.不能有相同长度超2的子串重复
 * 说明:长度超过2的子串
 * 输入描述:
 * 一组或多组长度超过2的子符串。每组占一行
 * 输出描述:
 * 如果符合要求输出：OK，否则输出NG
 */
import java.util.Scanner;

public class QualifiedCode {
	public static void main(String[] args) {
		String code = new String();
		Scanner sb = new Scanner(System.in);
		
		code = sb.nextLine();
		int a, b, c, d;
		if(code.length()<=8) {
			System.out.println("NG");
			return;
		}
		a=b=c=d=0;
		for(int i=0;i<code.length();i++) {
			if(code.charAt(i)>='a' && code.charAt(i)<='z')
				a=1;
			else if(code.charAt(i)>='A' && code.charAt(i)<='Z')
				b=1;
			else if(code.charAt(i)>='0' && code.charAt(i)<='9')
				c=1;
			else d=1;
		}
		if(a+b+c+d<3) {
			System.out.println("NG");
			return;
		}
		boolean flag = true;
		for(int i=3;i<(code.length()/2);i++) { //字串长度
			for(int j=0;j<code.length()-2*i;j++) {  //选取字串
				String sub1=code.substring(j, j+i);
				for(int k=j+i;k<code.length()-i;k++) {
					String sub2=code.substring(k, k+i);
					if(sub1.equals(sub2)) {
						flag = false;
						break;
					}
				}
			}
		}
		if(!flag) {
			System.out.println("NG");
			return;
		}
		System.out.println("OK");
	}

}
