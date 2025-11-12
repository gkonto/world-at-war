# World at War (C++20 + SFML 3)

# Prerequisites

I solemnly swear that this repository will not be abandoned halfway through like a half-implemented feature branch named “final_v3_really_final”. No, this time I’m committed. This project will be nurtured, debugged, refactored, and loved until it reaches its glorious, feature-complete destiny (or at least until it compiles without warnings). If future-me ever tries to walk away, let this README stand as a legally non-binding but morally embarrassing reminder to finish what I started.

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
./build/bin/world_at_war
```

For a release build:

```sh
cmake --preset release -S .
cmake --build --preset release
./build/bin/world_at_war
```

## Structure
- `src/` – source files (entry point in `main.cpp`)
- `assets/` – game assets (images, sounds, etc.)
- `CMakeLists.txt` – CMake build script
- `CMakePresets.json` – dev/release presets

## Notes
- This template requires SFML 3. If you only have SFML 2.x available, the CMake configure step will fail by design.
- On macOS or Linux, if SFML is installed via a package manager that provides a CMake config package, `find_package(SFML 3 CONFIG ...)` should work without extra configuration.
- Otherwise, set `-D SFML_DIR=/path/to/SFMLConfig.cmake/parent` when configuring.
