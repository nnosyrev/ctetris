
# Tetris

Just another Tetris game.

## Building on Linux

```
git clone https://github.com/nnosyrev/ctetris.git ctetris
cd ctetris
git submodule init
git submodule update
cmake -S . -B build
cmake --build build

build/tetris
```
