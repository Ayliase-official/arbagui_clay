# arbagui_clay
An implementation of the arbagui program written in C using the Clay 2D graphics layout library.

---

# Building and Running

## Build Using CMake
Uses CMake to auto-install all essential raylib libraries.

From the project root:
```sh
mkdir build
cd build
cmake ..
```

CMake will generate all the required files and download content from github.

Compile your executable by running this from your project root:
```sh
cd build
make
```

## Run Directly

Run the produced executable directly.

From the project root:
```sh
cd build
./arbagui
```

---

# Source
## `src`
Contains the main source files required to ruin the application. [here](./src/)

## `include`
Headers and other files used to compile the binary. 
- [raylib for clay](./include/raylib)
- [clay](./include/clay/)

## `assets`
All textual, grpahical and auditory assets required by the application. 
- [textual](./assets/texts/)
- [fonts](./assets/fonts/)
- [images](./assets/images/)
- [audios](./assets/audios/)
- [videos](./assets/videos/)
