# maze-gen

A terminal maze generator written in C++. Uses recursive depth-first search to carve a perfect maze and renders it with Unicode block characters.

```
███████████████████████████████
█   █     █   █         █     █
█ █ █ ███ █ █ ███████ █ █ ███ █
█ █   █   █ █       █ █   █   █
█ █████ ███ █████ █ █████ █ ███
█       █   █     █       █   █
█████ █ █ ███ █████████████ █ █
█     █ █     █       █     █ █
█ ███████████ █ █████ █ █████ █
█ █           █     █   █    X
███████████████████████████████
```

## How it works

The maze is represented as a 30×30 grid where cells sit at even indices and walls occupy odd indices between them. The algorithm starts from the center of the top row and recursively visits unvisited neighbors in random order, carving passages by zeroing out the wall between the current cell and its chosen neighbor.

The result is a **perfect maze** — exactly one path exists between any two cells, with no loops.

- `█` — wall
- ` ` — passage
- `X` — exit (bottom edge)

## Build

Requires C++20 and CMake ≥ 4.2.

```sh
cmake -B build
cmake --build build
./build/maze_gen
```

Every run produces a unique maze (seeded by system time).
