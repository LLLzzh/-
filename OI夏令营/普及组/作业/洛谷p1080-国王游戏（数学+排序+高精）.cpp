# include <iostream>
# include <algorithm>
# include <string>
# include <sstream>
using namespace std;
typedef long long ll;
struct info
{
	int l,r;
	ll res;
};
bool cmp1(info a,info b){return a.res < b.res;}
string trans(int x)
{
	stringstream ss;
	ss.clear();
	string s;
	ss<<x; ss>>s;
	return s;
} 
//加法 
int cmp(string a,string b)
{
	while(a[0] == '0' && a.length() != 1) a = a.substr(1,a.length()-1);
	while(b[0] == '0' && b.length() != 1) b = b.substr(1,b.length()-1);
	if(a.length() < b.length()) return -1;
	if(a.length() > b.length()) return 1;
	for(int i = 0;i < a.length();i++)
		if(a[i] != b[i]) return (a[i] < b[i]?-1:1);
}
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

//减法 
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

//乘法 
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
string mult(string a,string b)
{
	string res = "",tail = "",tem;
	for(int i = b.length()-1;i >= 0;i--)
	{
		tem = mult_single(a,b[i]) + tail;
		tail += "0";
		res = add(res,tem);
	}
	while(res[0] == '0' && res.length() != 1) res = res.substr(1,res.length()-1);
	return res;
}
//整除 
string div(string a,string b)
{
	int j;
	bool f;
	char c;
	string res = "",k,mod;
	if(a.length() < b.length()) return "0";
	if(a.length() == b.length() && a < b) return "0";
	if(b == "1") return a;
	if(a == b) return "1";
	k = a.substr(0,b.length());j = b.length()-1;
	while(1)
	{
		f = 0;
		for(int i = 0;i < 9;i++)
		{
			if(cmp(mult_single(b,char(i+'0')),k) <= 0 && cmp(mult_single(b,char(i+1+'0')),k) == 1)
			{
				c = char(i+'0');
				f = 1;
				break;
			}
		}
		if(f == 0) c = '9';
		res += c;
		k = diff(k,mult_single(b,c));
		j++;
		if(j == a.length()) break;
		k += a[j];
	}
	while(res[0] == '0' && res.length() != 1) res = res.substr(1,res.length()-1);
	mod = diff(a,mult(b,res));
	return res;
}
int main(void)
{
	int n,ans[5000] = {0},v = 0;
	string res = "";
	info *a,king;
	cin>>n; a = new info [n];
	cin>>king.l>>king.r;
	for(int i = 0;i < n;i++)
	{
		cin>>a[i].l>>a[i].r;
		a[i].res = a[i].l*a[i].r; 
	}
	sort(a,a+n,cmp1);
	while(king.l != 0)
	{
		ans[v] = king.l%10;
		king.l /= 10;
		v++;
	}
	v = 0;
	for(int i = 0;i < n-1;i++)
	{
		for(int j = 0;j < 5000;j++) ans[j] *= a[i].l;
		for(int j = 0;j < 5000;j++)
		{
			ans[j] += v;
			v = ans[j]/10;
			ans[j] %= 10;
		}
	}
	for(int j = 0;j < 5000;j++) res = char(ans[j]+'0') + res;
	res = div(res,trans(a[n-1].r));
	if(res == "0") res = "1";
	cout<<res<<endl;
	return 0;
} 
