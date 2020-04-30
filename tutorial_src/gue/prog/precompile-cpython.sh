rm -rf *.o *wrap*

# SWGI
rm -rf create-tmp-dir
mkdir create-tmp-dir
cp guelib.i create-tmp-dir/.
cp guelib.cpp create-tmp-dir/.
cp guelib.h create-tmp-dir/.
cd create-tmp-dir
swig3.0 -c++ -python guelib.i
g++ -std=c++11 -O3 -fPIC -c guelib.cpp
g++ -std=c++11 -O3 -fPIC -c guelib_wrap.cxx -I/usr/include/python3.6
g++ -shared guelib.o guelib_wrap.o -o _guelib.so
cp _guelib.so ..
cp guelib.py ..
cd ..
rm -rf create-tmp-dir
