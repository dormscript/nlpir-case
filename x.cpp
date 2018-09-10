#include <cstdio>
#include <string>
#include <iostream>
 
using namespace std;

int main(void)
{
	string content;
	while(1) {
		content = "";
		cin >> content;
		if ( cin.eof() || cin.bad() ) {
	        break;
	    }
		printf("\n结果：%s\n", content.c_str());
	}
	return 0;
}