#/bin/sh
# Install the ctstring library.

path=`realpath "$0"`
parent=`dirname "$path"`
root=`dirname "$parent"`
install_location="/usr/local/include"
library_location="/usr/local/lib"
project_location="$install_location/ctools"

cc="gcc"
cflags="-c -fpic -ansi -pedantic -Wall -Wextra -Wshadow -Wdouble-promotion -Wconversion"

printf "Parent directory: '%s'\n" "$parent"
printf "Project directory: '%s'\n" "$root"
printf "Installing headers to '%s'\n" "$project_location"
printf "Installing shared objects to '%s'\n" "$library_location"

# Add headers
sudo mkdir "$project_location" -p
sudo cp "$root/src/ctstring.h" "$project_location"

# Compile into shared object
sudo $cc "$root/src/ctstring.c" $cflags
sudo $cc "$root/ctstring.o" -shared -o "$library_location/libctstring.so"
rm -f ctstring.o


printf "Installed.\n"


