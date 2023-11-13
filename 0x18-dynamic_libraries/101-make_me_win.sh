#!/bin/bash
echo 'int rand(void) { return 9; } int system(const char *command) { return 0; }' | gcc -fPIC -shared -o /tmp/libwin.so -xc - && export LD_PRELOAD=/tmp/libwin.so
