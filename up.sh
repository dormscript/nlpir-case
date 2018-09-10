#更新代码shell

svn up /data/nlpir/"license";

dirlist='DocExtractor KeyExtract Summary';
for v in $dirlist
do
	svn up /data/nlpir/$v
	cp -f /data/nlpir/"license"/$v*/*.user /data/nlpir/$v/Data/
	cd ..
done

cp -f /data/nlpir/"license"/cluster*/*.user /data/nlpir/Cluster/Data/
