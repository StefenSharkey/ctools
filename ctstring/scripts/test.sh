# Build, and run tests

CC="gcc"
CFLAGS="-pedantic -Wno-unused-parameter -Wno-implicit-function-declaration -Wall -Wextra -Wshadow -Wdouble-promotion -Wconversion -g"
LINKER=""

path=`realpath "$0"`
parent=`dirname "$path"`
root=`dirname "$parent"`

$CC $root/tests/ctstring_compare.c $root/src/ctstring.c
$1 ./a.out
echo 'Passed comparison tests'

$CC $root/tests/ctstring_init.c $root/src/ctstring.c
$1 ./a.out
echo 'Passed initialization tests'

$CC $root/tests/ctstring_concat.c $root/src/ctstring.c
$1 ./a.out
echo 'Passed concatenation tests'

$CC $root/tests/ctstring_split.c $root/src/ctstring.c
$1 ./a.out
echo 'Passed split tests'

$CC $root/tests/ctstring_slice.c $root/src/ctstring.c
$1 ./a.out
echo 'Passed slicing tests'

$CC $root/tests/ctstring_cut.c $root/src/ctstring.c
$1 ./a.out
echo 'Passed cutting tests'

$CC $root/tests/ctstring_find.c $root/src/ctstring.c
$1 ./a.out
echo 'Passed searching tests'

$CC $root/tests/ctstring_to_nt.c $root/src/ctstring.c
$1 ./a.out
echo 'Passed NUL-conversion tests'

$CC $root/tests/ctstring_nt_to_ctstring.c $root/src/ctstring.c
$1 ./a.out
echo 'Passed ctstring-conversion tests'

$CC $root/tests/ctstring_lower.c $root/src/ctstring.c
$1 ./a.out
echo 'Passed lowering tests'

$CC $root/tests/ctstring_upper.c $root/src/ctstring.c
$1 ./a.out
echo 'Passed uppering tests'

rm ./a.out
