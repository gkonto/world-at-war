# AsteroidClone (C++20 + SFML 3)

A minimal starter for an Asteroids-style game using C++20 and SFML 3, built with CMake.

## Requirements
- CMake 3.22+
- A C++20 compiler (Clang, GCC, or MSVC)
- SFML 3 installed and discoverable by CMake

If CMake cannot find SFML automatically, set the `SFML_DIR` cache variable to the folder that contains `SFMLConfig.cmake` (e.g., `/path/to/sfml/lib/cmake/SFML`).

## Build
Using CMake presets (native Makefiles on macOS):

```sh
# Configure
cmake --preset dev-debug -S .

# Build
cmake --build --preset dev-debug

# Run
./build/debug/bin/asteroid-clone
```

For a release build:

```sh
cmake --preset release -S .
cmake --build --preset release
./build/release/bin/asteroid-clone
```

## Structure
- `src/` – source files (entry point in `main.cpp`)
- `include/` – public headers
- `assets/` – game assets (images, sounds, etc.)
- `CMakeLists.txt` – CMake build script
- `CMakePresets.json` – dev/release presets

## Notes
- This template requires SFML 3. If you only have SFML 2.x available, the CMake configure step will fail by design.
- On macOS or Linux, if SFML is installed via a package manager that provides a CMake config package, `find_package(SFML 3 CONFIG ...)` should work without extra configuration.
- Otherwise, set `-D SFML_DIR=/path/to/SFMLConfig.cmake/parent` when configuring.
