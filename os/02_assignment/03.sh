# Write a shell script which displays vendor id, model name, cpu MHz, cache size information about the processor present in your computer. Hint: most of this information can be obtained by reading the file /proc/cpuinfo.

echo "----------------------------------------" 
echo "Program Problem Statement : "
echo "Write a shell script which displays vendor id, model name, cpu MHz, cache size information about the processor present in your computer. Hint: most of this information can be obtained by reading the file /proc/cpuinfo."
echo "----------------------------------------"
echo ""
echo ""
# Display vendor id, model name, cpu MHz, and cache size
echo "Vendor ID: $(grep 'vendor_id' /proc/cpuinfo | head -n 1 | awk '{print $3}')"
echo "Model Name: $(grep 'model name' /proc/cpuinfo | head -n 1 | cut -d ':' -f2 | xargs)"
echo "CPU MHz: $(grep 'cpu MHz' /proc/cpuinfo | head -n 1 | awk '{print $4}')"
echo "Cache Size: $(grep 'cache size' /proc/cpuinfo | head -n 1 | cut -d ':' -f2 | xargs)"
echo ""
echo "----------------------------------------"
echo "End of Program"
echo "----------------------------------------"
echo ""