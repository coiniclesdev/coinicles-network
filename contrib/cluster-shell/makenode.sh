mkdir coinicles$1
cd coinicles$1
ln -s ../coiniclesnet coiniclesnet$1
cp ../coiniclesnet.ini .
nano coiniclesnet.ini
cd ..
echo "killall -9 coiniclesnet$1" >> ../stop.sh
