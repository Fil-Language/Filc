#!/bin/bash

filename=bin/rrd-antlr4-0.1.2.jar

if [ -f $filename ]; then
  java -jar $filename src/lib/grammar/FilParser.g4 --simple
  mv output/FilParser/index.html src/lib/grammar/diagram.html
  rm -rf output
else
  echo -e "\033[31m$filename not found, please download it here: https://github.com/bkiers/rrd-antlr4\033[0m"
fi
