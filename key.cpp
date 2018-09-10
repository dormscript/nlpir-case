#include <cstdio>
#include <string>
#include <assert.h>
#include <iostream>
#include "func.h"
#include "KeyExtract.h"

using namespace std;

int main(void)
{
	string content;
	if (!KeyExtract_Init("/data/nlpir/KeyExtract", 1))
	{
		printf("\n初始化失败\n");
		return 0;
	}
	while(1) {
		getline(cin,content);
		string sResult = KeyExtract_GetKeyWords(content.c_str(), 50, 0);
		printf("%s\n", sResult.c_str());
	}
	KeyExtract_Exit();
	return 0;
}