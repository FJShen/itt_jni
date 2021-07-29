#!/bin/bash
export JAVA_HOME=/home/shen449/jdk8u/build/linux-x86_64-normal-server-fastdebug/jdk
java -Xcomp -Djava.library.path=. -jar target/itt_jni-1.0.jar ITT