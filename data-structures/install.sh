# Install all data structures into the ctools directory in the system headers

for dir in function/*; do
    cd $dir
    sudo make install
    cd ..
    cd ..
done
