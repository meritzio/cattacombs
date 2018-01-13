# Cattacombs
A simple library for generating asset geometry with internal procedural pathways in OBJ (and maybe FBX) format using basic standalone geometry types

## What does it do?
It takes a graph of geometrically connected lines (currently just linear support), interprets these as routes and builds a 3D catacomb-like geometry asset.
The intention is to create procedurally generated 3D catacomb mazes for use as in-game assets.

## The build system
The build system is dependent on CMake, but given the simplicity of the classes you could put your own together.
Bourne shell files 'build' and 'clean' are included for convenience.

- Linux Use: "./build.sh"
- Windows Use: "./build.sh windows"

Note that for windows usage, the build relies on the git bash and MinGW, and will build 32-bit.
You may need to call the command more than once to produce the build because of the git sh.exe in PATH, MinGW does not like this.

## The generation plan
1. A closed boundary volume is provided for placement of the external nodes (entrances/exits)
2. The external nodes are placed procedurally on the surfaces according to external placement rules
3. The internal nodes are placed within the boundary surface volume according to internal placement rules
4. A graph is generated from the nodes in order to generate the catacomb branches, according to connection rules (no route collision, for example)
5. Geometry of the graph is created, the external surface forms the basis of geometry making
6. The resulting surface model is triangulated and exported to OBJ(/FBX).

