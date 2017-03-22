aclocal
autoconf
automake --add-missing
./configure CFLAGS='-std=c99'
make
sudo make install
make clean
