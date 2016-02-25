#! /bin/sh
set -e
docker run --rm --volume "$PWD":/data/source --workdir /data/source gcc make
docker build -t ls .
docker run ls
