# arbagui_clay
An implementation of the arbagui program written in C using the Clay 2D graphics layout library.

---

# Building and Running
Uses the Meson build system (alongside ninja).

Install both either via native package manager or using:
```sh
python -m pip install meson
python -m pip install ninja
```

## Building

From project root go to the build directory and compile:
```sh
cd build
meson compile
```

# Running

Executable is generated in `build` folder. Run directly:
```sh
cd build
./arbagui
```

File was originally built in windows for testing. Thus executable has a different extension:
```sh
cd build
./arbagui.exe
```

---

# Source

## Raylib
The project uses the Raylib 2D graphics library. [raylib src](./raylib/include/)

## `src`
Contains the main source files required to ruin the application. [here](./src/)

## `include`
Headers and other files used to compile the binary. 
- [raylib for clay](./include/raylib)
- [clay](./include/clay/)

## `assets`
All textual, grpahical and auditory assets required by the application. 
- [textual](./assets/texts/)
- [font](./assets/fonts/)
- [images](./assets/images/)
- [audios](./assets/audios/)
- [videos](./assets/videos/)