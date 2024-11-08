#!/bin/bash

# Define service file path and name
SERVICE_NAME="my_simple_service"
SERVICE_PATH="/etc/systemd/system/$SERVICE_NAME.service"

# Create the systemd service file
cat <<EOF | sudo tee $SERVICE_PATH > /dev/null
[Unit]
Description=My Simple Service
After=network.target

[Service]
ExecStart=/path/to/your/script.sh
WorkingDirectory=/path/to/your
ExecStartPre=/bin/sleep 5
Restart=always
User=your_user
Group=your_group

[Install]
WantedBy=multi-user.target
EOF

# Reload systemd to recognize the new service
sudo systemctl daemon-reload

# Enable and start the service
sudo systemctl enable $SERVICE_NAME
sudo systemctl start $SERVICE_NAME

echo "Service '$SERVICE_NAME' created, enabled, and started."
