#!/bin/bash

REMOTE_FILE_PATH="/home/pi4/project/build/DHT_11.csv"
DESTINATION_USER="embabi"
DESTINATION_HOST="192.168.1.7"
DESTINATION_DIR="/home/embabi/D/"


# Interval in seconds (60 seconds)
INTERVAL=60


# Infinite loop to send the file periodically
while true; do
	echo "$(date): sending csv file to $DESTINATION_USER@$DESTINATION_HOST:$DESTINATION_DIR" 
	# Send the file using scp
    	scp "$REMOTE_FILE_PATH" "$DESTINATION_USER@$DESTINATION_HOST:$DESTINATION_DIR"
	
	if [[ $? -eq 0 ]]; then
		echo "$(date): File sent successfully!"
	else
		echo "$(date): Failed to send file. Retrying in $INTERVAL seconds."
	fi
    	
	# Wait for the next interval
	sleep $INTERVAL
done
