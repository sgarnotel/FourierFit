#!/bin/sh

SRC_DIR=$(pwd)
BUILD_DIR='/.../build'	#to define
QMAKE='/.../qmake'	#to define

mkdir $BUILD_DIR
cd $BUILD_DIR
$QMAKE $SRC_DIR
make
cp -R $SRC_DIR/img $BUILD_DIR/img
cp -R $SRC_DIR/system $BUILD_DIR/system



