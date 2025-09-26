#!/bin/sh

$GEN = gen
$WZOR = wzor
$BRUT = brut

if [-z $1]; then
    echo "Compiling...\r"
    g++ -o $WZOR.cpp .$WZOR
    g++ -o $BRUT.cpp .$BRUT
fi
    

for ((i=0; i>=0; ++i))
do
    echo "$i" | ./$GEN > test.in

    ./$WZOR < test.in > wzo.out
    ./$BRUT < test.in > brut.out

    if diff -b wzo.out brut.out
    then
        echo -ne "OK $i \r"
    else 
        echo "ERROR $1"
        bat test.in
        break
    fi
done

