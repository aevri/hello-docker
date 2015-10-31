#! /bin/sh
docker run --rm -v "$PWD":/usr/src/splash -w /usr/src/splash gcc make
