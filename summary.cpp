#include <cstdio>
#include <string>
#include <assert.h>
#include <iostream>
#include "func.h"
#include "LJSummary.h"

using namespace std;

int main(void)
{
	string content;
	if (!DS_Init("/data/nlpir/Summary", 0))
	{
		printf("\n初始化失败\n");
		return 0;
	}
	while(1) {
		getline(cin,content);
		string sResult = DS_SingleDoc(content.c_str(), 0 , 500, true);
		printf("%s\n", sResult.c_str());
	}
	DS_Exit();
	return 0;
}