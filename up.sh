#!/bin/bash
#更新代码shell

svn up ../license;

dirlist='KeyExtract Summary';
for v in $dirlist
do
	svn up ../$v
	cp -f ../license/$v*/*.user ../$v/Data/
done
