#!/bin/bash

java -jar bin/rrd-antlr4-0.1.2.jar src/lib/grammar/FilParser.g4 --simple

mv output/FilParser/index.html src/lib/grammar/diagram.html

rm -rf output
