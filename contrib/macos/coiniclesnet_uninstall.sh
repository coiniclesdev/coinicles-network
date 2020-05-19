#!/bin/sh

touch /var/lib/coiniclesnet/suspend-launchd-service # Prevent restarting on exit
killall coiniclesnet
sleep 5  # Give it some time to shut down before we bring launchd into this
launchctl stop network.coinicles.coiniclesnet.daemon
launchctl unload /Library/LaunchDaemons/network.coinicles.coiniclesnet.daemon.plist


rm -rf /Library/LaunchDaemons/network.coinicles.coiniclesnet.daemon.plist
rm -rf /Applications/CoiniclesnetGUI.app
rm -rf /var/lib/coiniclesnet
rm -rf /usr/local/coiniclesnet/
rm -rf /opt/coiniclesnet

