# pycoiniclesnet

coiniclesnet with python 3

    # python3 setup.py install

## bootserv

bootserv is a bootstrap server for accepting and serving RCs

    $ gunicorn -b 0.0.0.0:8000 pycoiniclesnet.bootserv:app

## pycoiniclesnet instance

obtain `libcoiniclesnet-shared.so` from a coiniclesnet build

run (root):
    
    # export LOKINET_ROOT=/tmp/coiniclesnet-instance/
    # export LOKINET_LIB=/path/to/libcoiniclesnet-shared.so
    # export LOKINET_BOOTSTRAP_URL=http://bootserv.ip.address.here:8000/bootstrap.signed
    # export LOKINET_PING_URL=http://bootserv.ip.address.here:8000/ping
    # export LOKINET_SUBMIT_URL=http://bootserv.ip.address.here:8000/
    # export LOKINET_IP=public.ip.goes.here
    # export LOKINET_PORT=1090
    # export LOKINET_IFNAME=eth0
    # python3 -m pycoiniclesnet