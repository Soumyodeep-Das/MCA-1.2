# The PATH variable is an environment variable that contains an ordered list of paths that Linux will search for executables when running a command. Write a shell script to display all the directories in the PATH variable in a simple way, i.e., one line per directory. In addition, display information about each directory, such as the permissions and the modification times.

echo "----------------------------------------"
echo "Program Problem Statement : "
echo "The PATH variable is an environment variable that contains an ordered list of paths that Linux will search for executables when running a command. Write a shell script to display all the directories in the PATH variable in a simple way, i.e., one line per directory. In addition, display information about each directory, such as the permissions and the modification times."
echo "----------------------------------------"
echo ""
echo ""

# # Get the PATH variable
# IFS=':' read -r -a path_dirs <<< "$PATH"

# # echo "IFS = $IFS"
# # echo "PATH = $PATH"

# # Loop through each directory in the PATH variable
# for dir in "${path_dirs[@]}"; do
#   # Check if the directory exists
#   if [ -d "$dir" ]; then
#     # Get the permissions and modification time
#     permissions=$(ls -ld "$dir" | awk '{print $1}')
#     mod_time=$(stat -c %y "$dir")
#     # Display the directory, permissions, and modification time
#     echo "Directory: $dir"
#     echo "Permissions: $permissions"
#     echo "Modification Time: $mod_time"
#     echo ""
#   else
#     echo "$dir does not exist."
#   fi
# done
# echo ""
# echo "End of Program"   
# echo "Program Ended"
# echo "----------------------------------------"
# echo ""

# Loop through each directory in the PATH variable
IFS=':' # Set Internal Field Separator to ':'
for dir in $PATH; do
  # Check if the directory exists
  if [ -d "$dir" ]; then
    # Display the directory, permissions, and modification time directly
    echo "Directory: $dir"
    ls -ld "$dir" | awk '{print "Permissions: "$1}'
    stat -c "Modification Time: %y" "$dir"
    echo ""
  else
    echo "$dir does not exist."
  fi
done

echo "----------------------------------------"
echo "End of Program"
echo "----------------------------------------"