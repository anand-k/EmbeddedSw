#!/bin/bash

echo "List of wireless interface:"
winterfaces=$(ls /sys/class/net)
echo $winterfaces
echo "--------------------------------------------"
echo "Please enter the wifi interface the wireless interface:"
read wifiinterface
echo "--------------------------------------------"
echo "Please enter the routers ip address:"
read pingaddress
echo "--------------------------------------------"

count=0
echo "Interface: $wifiinterface pingaddress: $pingaddress"
echo "  Time | Count | Output | Ping"
echo "--------------------------------------------"

while [ $count -eq 4 ]
do
	count=$((count+1))
	countf=$(printf "%s" $count)
	wifioutput=$(sudo iwlist $wifiinterface scan essid anand | grep -i Quality)
	pingoutput=$(ping -c 1 $pingaddress | grep -E -o -m 1 'time.{0,10}')
	curtime=$(date +%d/%m/%y\ %H:%M:%S)
	echo [$curtime] "|" $countf "|" $wifioutput "|" $pingoutput
done
