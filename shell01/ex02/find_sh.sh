#!/bin/zsh

find . -type f -name "*.sh" -print0 | xargs -0 -I {} basename -s .sh {}