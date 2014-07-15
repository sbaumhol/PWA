#!/bin/bash
gcc cmake/IncreaseBuild.c -o build/bin/IncreaseBuild
build/bin/IncreaseBuild src/Build.h
gcc src/*.cpp -fPIC -pthread -w -O3 -s -march=native -L$ROOTSYS/lib/root -lCore -lCint -lRIO -lNet -lHist -lGraf -lGraf3d -lGpad -lTree -lRint -lPostscript -lMatrix -lPhysics -lMathCore -lThread -lGui -pthread -lm -ldl -rdynamic -lEG -lstdc++ -I$ROOTSYS/include/root -lMinuit -o build/bin/PWA