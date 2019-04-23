!# /bin/bash
echo "Name of the file"
read a
if [ -w $a ]
then
echo file is writable
else
echo file is not writable
fi