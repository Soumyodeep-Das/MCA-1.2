# Write a shell script to show your home directory, Operating System type, version, release number, kernel version and current path setting. Hint: use uname command or use content of /proc/sys/kernel/osrelease file.

echo "----------------------------------------"
echo "Program Problem Statement : "
echo "Write a shell script to show your home directory, Operating System type, version, release number, kernel version and current path setting. Hint: use uname command or use content of /proc/sys/kernel/osrelease file."
echo "----------------------------------------"
echo ""
echo ""
# Display home directory
echo "Home Directory: $HOME"
# Display Operating System type
echo "Operating System Type: $(uname -s)"
# Display Operating System version
echo "Operating System Version: $(uname -v)"
# Display Operating System release number
echo "Operating System Release Number: $(uname -r)"
# Display kernel version
echo "Kernel Version: $(uname -o)"
# Display current path setting
echo "Current Path Setting: $PATH"
echo ""
echo "----------------------------------------"     
echo "End of Program"
echo "----------------------------------------"
echo ""