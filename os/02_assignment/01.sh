# Write a shell script which, for all files in present directory displays whether it is a regular file or a directory.

echo "----------------------------------------"
echo "Program Problem Statement : "
echo "Write a shell script which, for all files in present directory displays whether it is a regular file or a directory."

echo "----------------------------------------"
echo ""
echo ""

for item in *; do
  if [ -f "$item" ]; then
    echo "$item is a regular file."
  elif [ -d "$item" ]; then
    echo "$item is a directory."
  else
    echo "$item is neither a regular file nor a directory."
  fi
done

echo ""
echo "End of Program"
echo "Program Ended"
echo "----------------------------------------"