# include <iostream>
using namespace std;
string add(string a,string b)
{
	string res = "";
	bool f = 0;
	int k;
	while(a.length() < b.length()) a = "0"+a;
	while(b.length() < a.length()) b = "0"+b;
	for(int i = a.length()-1;i >= 0;i--)
	{
		k = int(a[i]-'0') + int(b[i]-'0') + f;
		if(k > 9)
		{
			k -= 10;
			f = 1;
		}
		else f = 0;
		res = char(k+'0') + res;
	}
	if(f == 1) res = "1" + res;
	return res;
}
string diff(string a,string b)
{
	string res = "";
	bool f = 0,flag = 0;
	int tem;
	while(a.length() < b.length()) a = "0"+a;
	while(b.length() < a.length()) b = "0"+b;
	if(a < b)
	{
		swap(a,b);
		flag = 1;
	}
	for(int i = a.length()-1;i >= 0;i--)
	{
		tem = int(a[i]-'0') - f - int(b[i]-'0');
		f = (tem < 0?1:0);
		if(f == 1 && i) tem += 10;
		res = char(tem+'0') + res;
	}
	while(res[0] == '0' && res.length() != 1) res = res.substr(1,res.length()-1);
	if(flag == 1) res = "-"+res;
	return res;
}
string mult_single(string a,char b)
{
	int f = 0,k;
	string res = "";
	for(int i = a.length()-1;i >= 0;i--)
	{
		k = int(a[i]-'0') * int(b-'0') + f;  
		res = char(k%10 + '0') + res;
		f = k/10; 
	}
	if(f != 0) res = char(f+'0') + res;
	return res;
}
string solve(string n)
{
	if(n == "0") return "0";
	if(n == "1" || n == "2" || n == "3") return (n+"0");
	n = diff(n,"1");
	return add((n+"0"),mult_single(n,'4'));
}
int main(void)
{
	string n; cin>>n;
	cout<<solve(n)<<endl; 
	return 0;
} 
