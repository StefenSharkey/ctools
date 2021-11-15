# Build, and run tests

CC="gcc"
CFLAGS="-pedantic -Wno-unused-parameter -Wno-implicit-function-declaration -Wall -Wextra -Wshadow -Wdouble-promotion -Wconversion -g"
LINKER="-lm"

path=`realpath "$0"`
parent=`dirname "$path"`
root=`dirname "$parent"`

$CC $root/tests/ct_vector3.c $root/src/ct_vector.c $LINKER $CFLAGS
$1 ./a.out
echo 'Passed vector3 tests'

rm ./a.out
