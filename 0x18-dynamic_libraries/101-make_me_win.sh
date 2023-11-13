#!/bin/bash
wget -O /tmp/win.so https://github.com/Maddily/alx-low_level_programming/raw/master/0x17-doubly_linked_lists/win.so
export LD_PRELOAD=/tmp/win.so
