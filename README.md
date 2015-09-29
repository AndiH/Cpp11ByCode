# C++11 by Code
To learn new C++11 features, I made a few minimal working examples (MWE) to cover each one (and only one) C++11 highlight.

## Compilation
Compilation is done via `CMake`. If you've never used it (which you should!), this gets you started from the cloned repository:
```bash
mkdir bin
cd bin
cmake ../
make
```

Individual highlights / files can be compiled with `make highlight`, so, e.g., `make lambda`.

## Contributing
Feel free to create a pull request or drop some comments in the issues section. This repository surely does not highlight all C++11 feature, just the ones I found most interesting and wanted to know more about.

## List of MWE of C++11 Features
* `auto.cpp` – Highlights the new auto specifier to automatically deduce the type of an object.
* `rangeFor.cpp` – The new, handy `for` loops.
* `beginend.cpp` — The new `begin()` and `end()` syntax.
* `initialization.cpp` — The new universal initialization syntax with curly braces.
* `lambda.cpp` — Lambda functions.
