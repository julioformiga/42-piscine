#!/bin/sh
ifconfig | grep "eth" | awk '{split($0, a, " "); print a[2]}'
