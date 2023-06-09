#!/bin/bash

echo "compiling java files....."
javac -d assignment1 *.java
echo "compilation done"

echo "starting RMI registry"
rmiregistry -J-Djava.class.path=assignment1
