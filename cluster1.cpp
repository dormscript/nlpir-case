#include <cstdio>
#include <string>
#include <sstream>
#include "func.h"
#include <iostream>  
#include <fstream> 
#include "LJCluster.h"

using namespace std;

int main(void)
{
	FILE *fp;
	int i = 1;
	string content;
	ostringstream ss;
	if (!CLUS_Init("/data/nlpir/Cluster", "", 0))
	{
		printf("初始化失败：%s\n" ,CLUS_GetLastErrMsg());
		printf("按任意键继续...");
		getchar();
		return 0;
	}

	/**
	* 根据文本内容聚类
	*/
	CLUS_SetParameter(100, 2000);

	fp = fopen("file.txt", "r");  
	if(fp) {  
	    char line[4096];  
	    while(1) {  
	        int len;  
	        line[0] = '\0';  
	        fgets(line, sizeof(line), fp);  
	        if(len == sizeof(line)-1) continue; //too long line, ignore it  
	        printf("%s", line);  

		   	ss.str("");
			ss << "文章" << i;
			CLUS_AddContent(line, ss.str().c_str());
			i++;

			printf("\nline: %s", line);

	        if(feof(fp)) {
	        	break;  
	        }
	    }
	    fclose(fp);  
	}
	// 打印结果
	if (CLUS_GetLatestResult("./ClusterResultByContent.xml"))
	{
		printf("根据【内容】聚类结果已经保存到文件，请到项目根目录下查看\n");
	}

	CLUS_Exit();

	printf("结束\n");
	printf("按任意键继续...\n");
	getchar();

	return 0;
}