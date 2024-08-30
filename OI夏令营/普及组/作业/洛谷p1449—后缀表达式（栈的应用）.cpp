# include <iostream>
# include <stack>
# include <cctype>
using namespace std;
int main(void)
{
	stack<int> a;
	int tem = -1,x,y;
	char c;
	while((c = getchar()) != '@')
	{
		if(isdigit(c))
		{
			if(tem == -1) tem = int(c-'0');
			else tem = tem*10 + int(c-'0');
		}
		else if(c == '.')
		{
			a.push(tem);
			tem = -1;
		}
		else
		{
			x = a.top();a.pop();
			y = a.top();a.pop();
			if(c == '+') a.push(y+x);
			else if(c == '-') a.push(y-x);
			else if(c == '*') a.push(y*x);
			else if(c == '/') a.push(y/x);
		}
	}
	cout<<a.top()<<endl;
	return 0;
}
