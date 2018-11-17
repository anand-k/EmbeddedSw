#!/bin/bash

# Use this script to make sure that each training PC has the right
# hardware, distribution and configuration.

echo
echo "This script will check that this PC is suitable for building Android"
echo
echo "Checking hardware..."
echo "--------------------"

FAILED=n

NUM_CPU=$(grep processor /proc/cpuinfo | wc -l)
echo -n "Number of CPU's: ${NUM_CPU}, "
if [ ${NUM_CPU} -eq 1 ]; then
    echo "\033[31mFAIL. Only one CPU: not powerful enough\033[0m"
    FAILED=y
else
    echo "OK"
fi

RAM_KBYTES=$(grep MemTotal /proc/meminfo | awk '{print $2}')
RAM_MBYTES=$(( ${RAM_KBYTES} / 1024 ))
echo -n "MiB of RAM: ${RAM_MBYTES}, "
if [ ${RAM_MBYTES} -lt 4096 ]; then
    echo -e "\033[31mOnly ${RAM_MBYTES} MiB RAM: we need at least 4 GiB.NOT OK\033[0m"
    FAILED=y
else
    echo "OK"
fi

DISK_KBYTES=$(df  ${HOME} | awk '{if (NR == 2) print $4}')
DISK_GBYTES=$(( ${DISK_KBYTES} / 1048576 ))
echo -n "Free disk space in directory ${HOME}: ${DISK_GBYTES} GiB, "
if [ ${DISK_GBYTES} -le 49 ]; then
    echo "\033[31mFAIL. Insufficient disk space in ${HOME}, we need at least 50 GiB\033[0m"
    FAILED=y
else
    echo "OK"
fi

# Check the distribution is Ubuntu 16.04
echo -n "Checking Linux distribution, "
DISTRIB_RELEASE=x
if [ -f /etc/lsb-release ]; then
    . /etc/lsb-release
fi
if [ $DISTRIB_RELEASE != "16.04" ]; then
    echo "\033[31mFAIL. The distribution must be Ubuntu 64-bit 16.04\033[0m"
    FAILED=y
else
    echo "Distribution version is $DISTRIB_RELEASE.OK"
fi

MACHINE_ARCH=$(uname -m)
echo -n "Machine architecture: ${MACHINE_ARCH}, "
if [ ${MACHINE_ARCH} != "x86_64" ]; then
    echo "FAIL. Must be 64-bit"
    FAILED=y
else
    echo "OK"
fi
if [ $FAILED == y ]; then
    echo
    echo -e "\033[31mFAIL"
    echo
    exit 1
fi

echo
echo -e "\033[32mPASS"
echo

exit 0
