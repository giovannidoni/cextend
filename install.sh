nppath=`python -c 'import numpy; print(numpy.get_include())'`
echo $nppath
CFLAGS="-I $nppath/numpy" python setup.py install --home=./
python setup.py install
cp build/lib.*/myext* ./cex/myext.so
