# include <iostream>
# include <string>
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
int main(void)
{
	string a[1001];
	int st,ed;
	a[0] = "0"; a[1] = "1"; a[2] = "2";
	for(int i = 3;i < 1001;i++) a[i] = add(a[i-2],a[i-1]);
	cin>>st>>ed;
	cout<<a[ed-st]<<endl;
	return 0;
} 
