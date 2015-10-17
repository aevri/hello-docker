#! /bin/sh
make
docker build -t hello .
docker run hello
