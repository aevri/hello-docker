#! /bin/sh
set -e
make
docker build -t ls .
docker run ls
