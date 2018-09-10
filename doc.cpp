#include <cstdio>
#include <string>
#include <assert.h>
#include <iostream>
#include "func.h"
#include "DocExtractor.h"

using namespace std;

int main(void)
{
	string content;
	if (!DE_Init("../DocExtractor", 1))
	{
		printf("\n初始化失败\n");
		return 0;
	}
	while(1) {
		getline(cin,content);
		if(content == "END") {
			break;
		}
		DOC_PARSER_HANDLE handle = DE_ParseDocE(content.c_str(), "", false, HTML_REMOVER_REQUIRED);
		
		string keywords = DE_GetResult(handle, DOC_EXTRACT_TYPE_KEYWORD);
		printf("%s\n", keywords.c_str());

	}
	DE_Exit();
	return 0;
}