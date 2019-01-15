#!/bin/bash

target="./.ycm_extra_conf.py"
ycmpy1="/home/jorshua/ycm_py/.ycm_extra_conf.beg"
ycmpy2="/home/jorshua/ycm_py/.ycm_extra_conf.end"
TMP=.tmp.txt

PWD=$(pwd)
PRJ=$(basename ${PWD})

#touch ${TMP}

filelist=$(find . | grep -E "^.*\.h$")

for file in ${filelist}
do
        echo $(dirname "${file}") >>${TMP}
done

cat ${ycmpy1} > ${target}

if [ -f $TMP ]
then DIR=$(cat ${TMP} | sort -u)
fi

for i in ${DIR}
do
        echo "'-I'" >> ${target}
        echo "'${i}'," >> ${target}
done

cat ${ycmpy2} >> ${target}

rm -rf ${TMP}

