#!/bin/bash

read -p "Choose a name for your server: " filename
touch "/home/embabi/D/${filename}.service"

handle_request() {
    echo "[$1]"
    read -p "$2" $3

    if [ $1 = "Service" ]; then
        read -p "$4" $5
        read -p "$6" $7
        read -p "$8" $9
    fi
}

# Variables to store user input
desc=""
after=""
wants=""
notify_type=""
exec_start=""
working_dir=""
restart=""
wanted_by=""

write_service_file() {
    echo "[Unit]" >>"/home/embabi/D/${filename}.service"
    echo "Description=${desc}" >>"/home/embabi/D/${filename}.service"
    
    # Add dynamic "After" directives
    if [ -n "$after" ]; then
        IFS=',' read -ra after_array <<< "$after"
        for after_item in "${after_array[@]}"; do
            echo "After=${after_item}" >>"/home/embabi/D/${filename}.service"
        done
    fi

    # Add dynamic "Wants" directives
    if [ -n "$wants" ]; then
        IFS=',' read -ra wants_array <<< "$wants"
        for wants_item in "${wants_array[@]}"; do
            echo "Wants=${wants_item}" >>"/home/embabi/D/${filename}.service"
        done
    fi

    echo "[Service]" >>"/home/embabi/D/${filename}.service"
    echo "Type=${notify_type}" >>"/home/embabi/D/${filename}.service"
    echo "ExecStart=${exec_start}" >>"/home/embabi/D/${filename}.service"
    echo "WorkingDirectory=${working_dir}" >>"/home/embabi/D/${filename}.service"
    echo "Restart=${restart}" >>"/home/embabi/D/${filename}.service"

    echo "[Install]" >>"/home/embabi/D/${filename}.service"
    echo "WantedBy=${wanted_by}" >>"/home/embabi/D/${filename}.service"
}

handle_request "Unit" "Description: " desc
handle_request "Service" "Type (e.g., notify): " notify_type "ExecStart: " exec_start "WorkingDirectory: " working_dir "Restart: " restart
handle_request "Install" "WantedBy: " wanted_by

# User input for multiple "After" items
read -p "Add 'After'  " after
# User input for multiple "Wants" items
read -p "Add 'Wants' items  " wants

write_service_file

# Copy file.services to systemd path
sudo cp "/home/embabi/D/${filename}.service" "/etc/systemd/system"
echo "${filename}.service successfully created in /etc/systemd/system"
