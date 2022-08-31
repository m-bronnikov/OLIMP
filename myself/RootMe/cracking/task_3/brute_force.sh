#!/bin/bash

filename="ch15.exe"

strings=$(strings $filename)
for cand in $strings
do
    result=$(wine $filename $cand)
    echo $cand - $result
done