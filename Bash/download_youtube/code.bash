#!/bin/bash

read -p "enter url video youtube " vidyoutube

#define output
outdir="/path/" #change this to your out path

#download the video
youtube-dl -o "$outdir/%(title)s.%(ext)s" "$vidyoutube"

# Check if the download was succes
if [ $? -eq 0 ]; then
    echo "Video has been successfully downloaded."
else
    echo "An error occurred while downloading the video."
fi
