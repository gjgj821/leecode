#!/usr/bin
awk '/^[0-9]{3}-[0-9]{3}-[0-9]{4}$|^\([0-9]{3}\) [0-9]{3}-[0-9]{4}$/ {print $0}' file.txt
