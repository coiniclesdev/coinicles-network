#!/bin/sh
# copy a coiniclesnet binary into this cluster
cp ../../coiniclesnet .
# generate default config file
./coiniclesnet -g -r coiniclesnet.ini
# make seed node
./makenode.sh 1
# establish bootstrap
ln -s coinicles1/self.signed bootstrap.signed
