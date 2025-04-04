#!/bin/zsh

ls -l | awk 'NR%2==1'