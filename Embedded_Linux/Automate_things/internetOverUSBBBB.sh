#! /bin/bash
echo "Starting BBB Internet-over-USB script"

ifconfig enx1cba8c9bb0d4 192.168.7.1
iptables --table nat --append POSTROUTING --out-interface wlp2s0 -j MASQUERADE
iptables --append FORWARD --in-interface enx1cba8c9bb0d4 -j ACCEPT
echo 1 > /proc/sys/net/ipv4/ip_forward

echo "End of the settings script"
