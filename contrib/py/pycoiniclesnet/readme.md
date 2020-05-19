# pycoiniclesnet

coiniclesnet with python 3

    # python3 setup.py install

## bootserv

bootserv is a bootstrap server for accepting and serving RCs

    $ gunicorn -b 0.0.0.0:8000 pycoiniclesnet.bootserv:app

## pycoiniclesnet instance

obtain `libcoiniclesnet-shared.so` from a coiniclesnet build

run (root):
    
    # export COINICLESNET_ROOT=/tmp/coiniclesnet-instance/
    # export COINICLESNET_LIB=/path/to/libcoiniclesnet-shared.so
    # export COINICLESNET_BOOTSTRAP_URL=http://bootserv.ip.address.here:8000/bootstrap.signed
    # export COINICLESNET_PING_URL=http://bootserv.ip.address.here:8000/ping
    # export COINICLESNET_SUBMIT_URL=http://bootserv.ip.address.here:8000/
    # export COINICLESNET_IP=public.ip.goes.here
    # export COINICLESNET_PORT=1090
    # export COINICLESNET_IFNAME=eth0
    # python3 -m pycoiniclesnet