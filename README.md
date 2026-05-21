## String Processing System

Console program for string searching using Boyer-Moore and Rabin-Karp. It loads text from a file or manual input, searches for one or more patterns, and reports statistics and match positions.

### Features
- Load text from a file or enter manually
- Search using Boyer-Moore or Rabin-Karp
- Compare both algorithms on the same pattern
- Report comparisons, matches, execution time, and match positions
- Highlight matches in the displayed text

### Project Structure
- main.cpp: Program entry point and menu
- file_io.h / file_io.cpp: File loading and manual input
- search_ui.h / search_ui.cpp: User interaction for searches and comparison
- search_algorithms.h / search_algorithms.cpp: Boyer-Moore and Rabin-Karp implementations
- output.h / output.cpp: Statistics output and match highlighting
- stats.h: Stats struct
- text_store.h / text_store.cpp: Global text storage

### Build and Run

#### VS Code (recommended)
1. Use Run and Debug and choose "Run main.exe".
2. The preLaunchTask builds all sources.

#### Command Line (g++)
From the project folder:

```
g++ -std=c++17 main.cpp file_io.cpp output.cpp search_algorithms.cpp search_ui.cpp text_store.cpp -o main
```

Run:

```
./main
```

On Windows, run:

```
main.exe
```

### Usage
1. Choose option 1 to load a text file or option 2 to enter text manually.
2. Choose a search option (3 or 4) or compare (5).
3. Enter the pattern(s) when prompted.
