rm -rf *.o *wrap*

# SWGI
rm -rf create-tmp-dir
mkdir create-tmp-dir
cp gue_lib.i create-tmp-dir/.
cp gue_lib.cpp create-tmp-dir/.
cp gue.h create-tmp-dir/.
cd create-tmp-dir
swig3.0 -c++ -python gue_lib.i
g++ -std=c++11 -O3 -fPIC -c gue_lib.cpp
g++ -std=c++11 -O3 -fPIC -c gue_lib_wrap.cxx -I/usr/include/python3.6
g++ -shared gue_lib.o gue_lib_wrap.o -o _gue_lib.so
cp _gue_lib.so ..
cp gue_lib.py ..
cd ..
rm -rf create-tmp-dir
