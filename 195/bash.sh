#!/bin/bash
awk 'BEGIN{count=0;}{count+=1;if(count==10){print $0}}' file.txt

