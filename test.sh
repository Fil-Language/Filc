#!/bin/bash

cd "$1" || exit
npm install
npm test