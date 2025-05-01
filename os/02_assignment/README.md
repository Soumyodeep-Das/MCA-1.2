# Operating Systems Assignment - Shell Scripts
=============================================

## Table of Contents
-----------------

1. [Problem Statements](#problem-statements)
2. [How to Run the Scripts](#how-to-run-the-scripts)
3. [Directory Structure](#directory-structure)
4. [Conclusion](#conclusion)

## Problem Statements
-------------------

### 1. Display File or Directory Type

#### Problem Statement

Write a shell script that iterates through all files in the current directory and displays whether each is a regular file or a directory.

#### Thought Process

* Use a `for` loop to iterate through all items in the current directory.
* Use conditional checks (`-f` for files, `-d` for directories) to determine the type of each item.
* Print the result for each item.

#### Code

Refer to `01.sh` for the implementation.

```bash
#!/bin/bash

for item in *; do
  if [ -f "$item" ]; then
    echo "$item is a regular file"
  elif [ -d "$item" ]; then
    echo "$item is a directory"
  fi
done
```

### 2. Display Directories in PATH

#### Problem Statement

Write a shell script to display all the directories in the `PATH` variable, one per line, along with their permissions and modification times.

#### Thought Process

* Split the `PATH` variable into individual directories using the `:` delimiter.
* Loop through each directory and check if it exists.
* Use `ls` and `stat` commands to retrieve permissions and modification times.

#### Code

Refer to `02.sh` for the implementation.

```bash
#!/bin/bash

IFS=':'
for dir in $PATH; do
  if [ -d "$dir" ]; then
    echo "$dir"
    ls -ld "$dir" | awk '{print $1}'
    stat -c %y "$dir"
  fi
done
```

### 3. Display Processor Information

#### Problem Statement

Write a shell script to display the vendor ID, model name, CPU MHz, and cache size of the processor. This information can be obtained from `/proc/cpuinfo`.

#### Thought Process

* Use `grep` to extract specific fields (`vendor_id`, `model name`, `cpu MHz`, `cache size`) from `/proc/cpuinfo`.
* Use `awk` or `cut` to isolate the required values.
* Display the extracted information in a user-friendly format.

#### Code

Refer to `03.sh` for the implementation.

```bash
#!/bin/bash

echo "Vendor ID: $(grep 'vendor_id' /proc/cpuinfo | head -n 1 | awk '{print $3}')"
echo "Model Name: $(grep 'model name' /proc/cpuinfo | head -n 1 | awk '{print $4}')"
echo "CPU MHz: $(grep 'cpu MHz' /proc/cpuinfo | head -n 1 | awk '{print $4}')"
echo "Cache Size: $(grep 'cache size' /proc/cpuinfo | head -n 1 | awk '{print $4}')"
```

### 4. Disk Space Usage Summary

#### Problem Statement

Write a shell script to display a summary of the disk space usage for each directory argument (and its subdirectories) in bytes, kilobytes, or megabytes.

#### Thought Process

* Use `du -sb` to get the total size of a directory in bytes.
* Use a function to convert bytes into human-readable formats (KB, MB).
* Loop through each directory argument and display the total size and sizes of subdirectories.

#### Code

Refer to `05.sh` for the implementation.

```bash
#!/bin/bash

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

if [ $# -eq 0 ]; then
  echo "Usage: $0 <directory> ..."
  exit 1
fi

for dir in "$@"; do
  if [ -d "$dir" ]; then
    echo "Summary for directory: $dir"
    echo "---------------------------------"

    total_bytes=$(du -sb "$dir" | awk '{print $1}')
    total_human=$(human_readable $total_bytes)

    echo "Total size: $total_bytes bytes ($total_human)"
    echo

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
```

## How to Run the Scripts
-------------------------

1. Make the script executable:
   ```bash
chmod +x *.sh
```
2. Run the script:
   ```bash
./<script_name>.sh [arguments]
```

## Directory Structure
---------------------

```
/home/ace/mca-ii/MCA-1.2/os/02_assignment/
├── 01.sh  # File or Directory Type
├── 02.sh  # Directories in PATH
├── 03.sh  # Processor Information
├── 05.sh  # Disk Space Usage Summary
└── README.md  # Documentation
```

## Conclusion
----------

This directory contains shell scripts that demonstrate the use of Linux commands, file handling, and text processing tools like `grep`, `awk`, and `du`. Each script is designed to solve a specific problem and is implemented with clarity and efficiency.

Feel free to explore and modify the scripts as needed.