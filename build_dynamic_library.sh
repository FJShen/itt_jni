#!/bin/bash

#javac is done by maven
#javac -source 1.8 -target 1.8 -cp src/main/java com/fangjia/itt/MyJniClass.java

javah -classpath src/main/java com.fangjia.itt.ITT
export JAVA_HOME=/usr/lib/jvm/java-8-openjdk-amd64/ 
export VTUNE_HOME=/opt/intel/oneapi/vtune/latest/ 
gcc com_fangjia_itt_ITT.c -Wall -g -fPIC -pthread -ldl -shared -I$VTUNE_HOME/sdk/include -L$VTUNE_HOME/sdk/lib64 -I$JAVA_HOME/include -I$JAVA_HOME/include/linux -L/home/shen449/ittapi/build_linux2/64/bin -I/home/shen449/ittapi/include -littnotify -o libittjni.so 
