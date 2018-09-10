CC = g++
SummaryCFLAGS = -I./../Summary/include/ -L./../Summary/lib/linux64/ -lLJSummary -D OS_LINUX
KeyCFLAGS = -I./../KeyExtract/include/ -L./../KeyExtract/lib/linux64/ -lKeyExtract -D OS_LINUX
DocCFLAGS = -I./../DocExtractor/include/ -L./../DocExtractor/lib/linux64/ -lDocExtractor -D OS_LINUX
ClusterFLAGS = -g -I./../Cluster/include/ -L./../Cluster/lib/linux64/ -lLJCluster -D OS_LINUX

summary : summary.o func.o
	$(CC) $(SummaryCFLAGS) -o summary func.o summary.o
summary.o : summary.cpp
	$(CC) $(SummaryCFLAGS) -c summary.cpp


key : key.o func.o
	$(CC) $(KeyCFLAGS) -o key func.o key.o
key.o : key.cpp
	$(CC) $(KeyCFLAGS) -c key.cpp


doc : doc.o func.o
	$(CC) $(DocCFLAGS) -o doc func.o doc.o
doc.o : doc.cpp
	$(CC) $(DocCFLAGS) -c doc.cpp

cluster : cluster.o func.o
	$(CC) $(ClusterFLAGS) -o cluster cluster.o func.o
cluster.o:
	$(CC) $(ClusterFLAGS) -c cluster.cpp

func.o : func.cpp
	$(CC) -c func.cpp
clean:
	rm -fr *.o
