QT_LIB=/usr/lib/x86_64-linux-gnu/cmake
QT_INCLUDE=/usr/include/x86_64-linux-gnu/qt5

version:
	g++ -o version version.cpp -I$(QT_INCLUDE)/QtCore -I$(QT_INCLUDE) -L$(QT_LIB) -lQt5Core -fPIC

clean:
	rm -rf version