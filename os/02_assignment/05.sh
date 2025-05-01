# Write a shell script to display a summary of the disk space usage for each directory argument (and any subdirectories), both in terms of bytes, and kilobytes or megabytes (whichever is appropriate). [du -b]

#!/bin/bash

# Function to convert bytes to human-readable format
human_readable() {
    local bytes=$1
    local kb=$((bytes / 1024))
    local mb=$((kb / 1024))

    if [ $mb -gt 0 ]; then
        echo "${mb}MB"
    elif [ $kb -gt 0 ]; then
        echo "${kb}KB"
    else
        echo "${bytes}B"
    fi
}

# Check if at least one argument is provided
if [ $# -eq 0 ]; then
    echo "Usage: $0 <directory1> <directory2> ..."
    exit 1
fi

# Loop through each directory argument
for dir in "$@"; do
    if [ -d "$dir" ]; then
        echo "Summary for directory: $dir"
        echo "---------------------------------"

        # Get the total size in bytes
        total_bytes=$(du -sb "$dir" | awk '{print $1}')
        total_human=$(human_readable $total_bytes)

        echo "Total size: $total_bytes bytes ($total_human)"
        echo

        # Get the size of each subdirectory in bytes
        echo "Subdirectory sizes:"
        du -b "$dir"/* 2>/dev/null | while read size path; do
            human_size=$(human_readable $size)
            echo "$path: $size bytes ($human_size)"
        done
        echo
    else
        echo "Error: $dir is not a directory"
    fi
done
