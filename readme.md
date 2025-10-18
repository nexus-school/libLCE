# LibLCE

[![Docs](https://img.shields.io/badge/Read%20Documentation-4e5151?logo=gitbook)](https://libLCE.dexrn.me)
![GitHub Downloads](https://img.shields.io/github/downloads/dexrnzacattack/libLCE/total)

C++ Library for Minecraft: Legacy Console Edition file formats

Downloads for Linux, macOS, Windows, and Emscripten (incomplete) are available
at https://nightly.link/DexrnZacAttack/libLCE/workflows/cmake-multi-platform/main?preview

> [!NOTE]
> Region and Chunk reading will be done in Lodestone.LCE w/
> Lodestone.Level ([libLodestone](https://github.com/Team-Lodestone/libLodestone))

> [!NOTE]
> This project's work will go towards [Project Lodestone](https://github.com/Team-Lodestone)
> and [libLodestone](https://github.com/Team-Lodestone/libLodestone).   
> Project Lodestone is an in-progress universal world converter, go [check it out](https://team-lodestone.github.io)!

## Progress

- [ ] File formats
    - [x] Savegame
        - [X] Reading
        - [X] Writing
    - [ ] World info (THUMB)
        - [X] Reading
        - [ ] Writing
    - [X] ARC
        - [X] Reading
        - [X] Writing
    - [X] LOC
        - [X] Reading
        - [X] Writing
    - [ ] PCK
        - [ ] Reading
        - [ ] Writing
    - [X] COL
        - [X] Reading
        - [X] Writing
    - [ ] MSSCMP
        - [X] Reading
        - [ ] Writing
- [ ] Compression
    - [ ] Zlib
    - [ ] LZX
    - [ ] Deflate (non-Zlib)
    - [ ] Split Save
    - [ ] Vita
    - [ ] Chunk
- [X] Decompression
    - [X] Zlib
    - [ ] LZX
    - [ ] Deflate (non-Zlib)
    - [ ] Split Save
    - [X] Vita
    - [X] Chunk
- [ ] World folder
    - [ ] Reading
    - [ ] Writing
