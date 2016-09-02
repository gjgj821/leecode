#!/bin/bash
awk '{for(i=1;i<=NF;i++){a[i]=a[i] " " $i;}}END{for(i in a) {gsub(/^ */,"",a[i]);print a[i]}}' file.txt
