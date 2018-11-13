#!/bin/bash

# store the current dir
CUR_DIR=$(pwd)

# Let the person running the script know what's going on.so echoing..
echo "Pulling in latest changes for all repositories...";echo ""
for j in $(find log_*.log) 
do
    echo -e "\033[1;31mDeleting existing log $j..\033[0m"
    rm $j
    echo ""
done

TODAY=`date '+%Y_%m_%d'`
FILENAME=log_$TODAY
LOGFILE=$(pwd)/$FILENAME.log

echo -e "\033[1;32mCreating new log file $FILENAME.log..\033[0m"

# Clear entries in file
cp /dev/null $LOGFILE

# Find all git repositories and update it to the master latest revision
for i in $(find . -name ".git" | cut -c 3-); do
    echo ""
    echo -e "\033[1;35mFound $i ...\033[0m"
    echo "`date +%Y-%m-%d.%H:%M:%S` : $i" >> $LOGFILE 2>&1;echo ""

    # We have to go to the .git parent directory to call the pull command
    cd "$i"
    cd ..

    # finally pull
    git fetch

    # lets get back to the CUR_DIR
    cd $CUR_DIR
done

echo "Complete!"
