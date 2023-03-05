# Fellowship

## Introduction

A Text Editor made using SFML and C++. Main Functionalities are -

- Text Insertion and Deletion.
- Text can be saved and read from file/text_file.txt.
- Editor rendered using SFML.

## Steps to compile

- Create a dep and inside that create 2 folder for SFML includes and SFML lib.
- Add SFML .dll's in the root of the project.
- On linux -

```
$ make
```

- On windows with MinGW installed -

```
$ mingw32-make
```

## Files

```
Fellowship/
├── file/
│ └── text_file.txt
├── fonts/
│ └── Roboto_mono/
│ └── RobotoMono-Medium.ttf
├── src/
│ ├── constants.hpp
│ ├── cursor.cpp
│ ├── cursor.hpp
│ ├── document.cpp
│ ├── document.hpp
│ ├── editor.cpp
│ ├── editor.hpp
│ ├── input_events.cpp
│ └── input_events.hpp
├── .gitignore
├── main.cpp
├── Makefile
└── README.md
```
