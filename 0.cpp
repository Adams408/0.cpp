//James Adams

#include <iostream>
#include <cstring>
#include "stack.cpp"
using namespace std;

int main(int argc, char *argv[])
{
	char* a = argv[1];
    int N = argc;
	stack<int> save(N);
	for(int i = 0; i < N; i++)
	{
		if(a[i] == '+')
			save.push(save.pop() + save.pop());
		if(a[i] == '-')
        {
            int sub = save.pop();
            save.push(save.pop() - sub);
        }
		if(a[i] == '*')
			save.push(save.pop() * save.pop());
        if(a[i] == '/')
        {
            int div = save.pop();
            save.push(save.pop() / div);
        }
		if((a[i] >= '0') && (a[i] <= '9')) {
            save.push(a[i++] - '0');
            for (; i < N; i++) {
                if (a[i] >= '0' && a[i] <= '9') {
                    int firstNum = save.pop() * 10;
                    firstNum+=a[i] - '0';
                    save.push(firstNum);
                }else break;
            }
        }
		//while ((a[i] >= '0') && (a[i] <= '9'))
		//	save.push(10*save.pop() + (a[i++]-'0'));
	}
	cout << save.pop() <<endl;
	return 0;
}