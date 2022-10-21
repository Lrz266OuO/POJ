/*
 * @Title: Exponentiation
 * @Description: 
 *      Problems involving the computation of exact values of very large magnitude and precision are common. For example, the computation of the national debt is a taxing experience for many computer systems.
 *      This problem requires that you write a program to compute the exact value of Rn where R is a real number ( 0.0 < R < 99.999 ) and n is an integer such that 0 < n <= 25.
 * @Input: 
 *      The input will consist of a set of pairs of values for R and n. The R value will occupy columns 1 through 6, and the n value will be in columns 8 and 9.
 * @Output: 
 *      The output will consist of one line for each line of input giving the exact value of R^n. Leading zeros should be suppressed in the output. Insignificant trailing zeros must not be printed. Don't print the decimal point if the result is an integer.
 * @Hint: 
 */

#include<iostream>
#include<algorithm>
#include<string.h>
#include<string>
using namespace std;
 
//高精度乘法 
string bigMul(string a,string b)
{
	int lengthA,lengthB,aInt[205],bInt[205],mul[205]={0},mark,start;
	reverse(a.begin(),a.end());
	reverse(b.begin(),b.end());
	lengthA=a.length();
	lengthB=b.length(); 
	for(int i=0;i<lengthA;i++)
	{
		aInt[i]=(int)(a[i]-'0');
	}
	for(int i=0;i<lengthB;i++)
	{
		bInt[i]=(int)(b[i]-'0');
	}
	//开始相乘 
	for(int i=0;i<lengthA;i++)
	{
		for(int j=0;j<lengthB;j++)
		{
			mul[i+j]+=aInt[i]*bInt[j];
		}
	}
	//处理
	for(int i=0;i<lengthA+lengthB;i++)
	{
		mul[i+1]+=(int)mul[i]/10;
		mul[i]=mul[i]%10;
		
	 } 
	 //结果转化成字符串
	 
	char mulChar[205];
	mark=204;
	while(mul[mark]==0)
	   mark--;
	start=0;
	for(int i=mark;i>=0;i--)
	{
		mulChar[start]=(char)(mul[i]+'0');
		start++;
	}
	mulChar[start]='\0';
	return (string)mulChar;
}
 
 
int main()
{
	string a;
	int n;
	while(cin>>a>>n)
	{
		int dotPos,resultDotPos; //小数点的位置
		string result=a;
		bool flagDot=true;  //无小数点   
		for(int i=0;i<6;i++)
		{
		    if(a[i]=='.')
		    { 
			    dotPos=i;
			    flagDot=false; 
			    break;
			}
    	}
    	
    	//去掉小数点，a保存到result中 
    	if(n>=2&&!flagDot)  
    	{
    		int start=0;
    		for(int i=0;i<6;i++)
    		{
    			 if(a[i]!='.')
    			 {
    			 	result[start++]=a[i];
				 }
			}
		    result=result.substr(0,5);
		}
 
		//开始相乘
		if(n>=2)
		{
			string tmp=result;
			for(int i=0;i<n-1;i++)
			{
				result=bigMul(result,tmp);
			}
		} 
		
		//输出处理
		//没有小数点 
		if(flagDot)
		{
			//除去无意义的零 
			int i;
			for( i=0;i<result.length();i++)
			   if(result[i]!='0')
			    break;
			for(;i<result.length();i++)
			   cout<<result[i];
			cout<<endl;	   
		} 
		
		//有小数点 
		else if(n>=2)
		{
			//计算小数点的离最后一位的位置
			resultDotPos=(5-dotPos)*n;
			int lengthResult=result.length();
			//去掉后面无意义的零
			int i=lengthResult-1;
			for(;i>=0;i--)
			   if(result[i]!='0'||(lengthResult-i>resultDotPos))
			   break; 
			result=result.substr(0,i+1);
			
			if(lengthResult<=resultDotPos)
			{
				cout<<".";
				for(int i=0;i<resultDotPos-lengthResult;i++)
				   cout<<"0";
				cout<<result<<endl;
			}
			else
			{
				i=0;
				for(;i<lengthResult-resultDotPos;i++)
				   cout<<result[i];
				if(i!=result.length())
				   cout<<".";
				for(;i<result.length();i++)
				   cout<<result[i];
				cout<<endl;
			} 
		}
		//有小数点且n=1
		else
		{
 
			int endZeros=5;
			for(;endZeros>=0;endZeros--)
			   if(result[endZeros]!='0'&&result[endZeros]!='.')
			      break;
			if(result[0]=='0'&&dotPos==1)
			{ 
				cout<<".";
				for(int i=2;i<=endZeros;i++)
				  cout<<result[i];
				cout<<endl;
			}
			else
			{
				for(int i=0;i<=(endZeros>(dotPos-1)?endZeros:(dotPos-1));i++)
				   cout<<result[i];
				cout<<endl;
			}
			   
		} 
		
    }
	return 0;
}
 
 
 
 
 
 
 
 
 
 
 
 
