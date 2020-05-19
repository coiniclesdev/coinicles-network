#!/bin/bash
set +x
cd coinicles1
nohup ./coiniclesnet1 $PWD/coiniclesnet.ini &
# seed node needs some time to write RC to make sure it's not expired on load for the rest
sleep 1
cd ../coinicles2
nohup ./coiniclesnet2 $PWD/coiniclesnet.ini &
cd ../coinicles3
nohup ./coiniclesnet3 $PWD/coiniclesnet.ini &
cd ../coinicles4
nohup ./coiniclesnet4 $PWD/coiniclesnet.ini &
cd ../coinicles5
nohup ./coiniclesnet5 $PWD/coiniclesnet.ini &
cd ..
tail -f coinicles*/nohup.out
