#include<iostream>
#include<string.h>
#include<math.h>
using namespace std;

void match(string s,string p)    
{
	int lenp=p.length();          //calculate length of pattern
	int lens=s.length();          //calculate length of String
	int q=126;                   //for calculating hash function
	int hashp=0,hashs=0; 
    for(int i=0;i<lenp;i++)
    {
    	hashp=hashp+int(p[i])*pow(q,lenp-i-1);      //hash function for pattern
	}
	hashp=hashp%(2^32);           //reducing value of hash function by mod
	
	
	for(int i=0;i<=lens-lenp;i++)    
	{ 
		for(int j=i;j<i+lenp;j++)
		{
			hashs=hashs+int(s[j])*pow(q,lenp-j-1+i);    //hash function for string
		} 
		hashs=hashs%(2^32);               //reducing value of hash function by mod
	
		if(hashs==hashp)
		{
			cout<<"Pattern found at index:"<<i;
		}
		hashs=0;
	}
}

int main()
{
	string s="aaryalamkhade";
	string p="lamkhade";
	match(s,p);
}
