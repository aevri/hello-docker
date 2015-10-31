#! /bin/sh
set -e
./make.sh
docker build -t splash .
docker run --rm splash
