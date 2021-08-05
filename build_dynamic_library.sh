#!/bin/bash

#javac is done by maven
#javac -source 1.8 -target 1.8 -cp src/main/java com/fangjia/itt/MyJniClass.java

javah -classpath target/classes com.fangjia.itt.ITT
export JAVA_HOME=/usr/lib/jvm/java-8-openjdk-amd64/ 
export VTUNE_HOME=/opt/intel/oneapi/vtune/latest/ 

export INTEL_LIBITTNOTIFY32=${VTUNE_HOME}/lib32/runtime/libittnotify_collector.so
export INTEL_LIBITTNOTIFY64=${VTUNE_HOME}/lib64/runtime/libittnotify_collector.so

#gcc -L$VTUNE_HOME/sdk/lib64 \
#-I$VTUNE_HOME/sdk/include -I$JAVA_HOME/include -I$JAVA_HOME/include/linux -I/home/shen449/ittapi/include \
#-Wall -g -fPIC -fstack-protector \
#com_fangjia_itt_ITT.c \
#-littnotify -ldl -pthread -shared -o libittjni.so 

gcc -c -I$VTUNE_HOME/sdk/include -I$JAVA_HOME/include -I$JAVA_HOME/include/linux -I/home/shen449/ittapi/include \
-Wall -Werror -g -fPIC com_fangjia_itt_ITT.c

gcc -shared -L$VTUNE_HOME/sdk/lib64 \
-I$VTUNE_HOME/sdk/include -I$JAVA_HOME/include -I$JAVA_HOME/include/linux -I/home/shen449/ittapi/include \
-o libittjni.so com_fangjia_itt_ITT.o -littnotify -ldl -pthread -ldl
