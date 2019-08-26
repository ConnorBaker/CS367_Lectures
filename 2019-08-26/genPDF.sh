#! /bin/bash

pandoc --template eisvogel Lecture.md -o Lecture.pdf --pdf-engine=lualatex
