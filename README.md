# Voxel Engine

🇫🇷  
Moteur voxel minimaliste développé en C++20 avec Raylib.  
Le projet sert de base pour expérimenter le rendu 3D, le raycasting, les interactions avec les blocs et la structure d’un monde voxel simple.

🇬🇧  
Minimal voxel engine developed in C++20 using Raylib.  
The project is a foundation for experimenting with 3D rendering, raycasting, block interactions, and the structure of a simple voxel world.

## Description

🇫🇷  
Le moteur gère pour l’instant :
- un monde voxel statique  
- une caméra FPS fournie par Raylib  
- un système de raycast permettant de détecter quel voxel est visé  
- l’ajout et la suppression de voxels via les faces détectées  
- une architecture simple basée sur des classes (`Map`, `Voxel`)  
- un build propre via CMake  

L’objectif est d’apprendre les bases d’un moteur 3D voxel tout en gardant une structure claire et extensible.

🇬🇧  
The engine currently supports:
- a static voxel world  
- Raylib’s built-in FPS camera  
- a raycast system to detect the targeted voxel  
- adding and removing voxels based on the selected face  
- a simple architecture with classes like `Map` and `Voxel`  
- a clean build system using CMake  

The goal is to learn the foundations of a 3D voxel engine while keeping the structure clean and extendable.

## Technologies / Stack

🇫🇷 / 🇬🇧  
- C++20  
- Raylib  
- CMake  
- Basic FPS camera handling  
- Custom voxel / map classes  

## Installation & Compilation

### 🇫🇷
1. Clonez le dépôt :  
git clone https://github.com/ygr671/voxel-engine  
cd voxel-engine

2. Compilez via CMake :  
mkdir build  
cd build  
cmake ..  
make -j$(nproc)

3. Lancez l’exécutable :  
./voxel-engine

### 🇬🇧
1. Clone the repository:  
git clone https://github.com/ygr671/voxel-engine  
cd voxel-engine

2. Build using CMake:  
mkdir build  
cd build  
cmake ..  
make -j$(nproc)

3. Run the executable:  
./voxel-engine

## Fonctionnalités / Features

### 🇫🇷 Déjà implémenté
- moteur voxel de base  
- rendu 3D simple via Raylib  
- caméra libre FPS  
- raycast pour sélectionner un voxel  
- ajout / suppression de voxels  
- structure du monde via classe `Map`  
- blocs représentés par la classe `Voxel`

### 🇬🇧 Implemented
- basic voxel engine  
- simple 3D rendering with Raylib  
- free FPS camera  
- raycast for voxel selection  
- add / remove voxel system  
- world structure through `Map` class  
- blocks represented by a `Voxel` class

## À venir / Planned

🇫🇷  
- gestion des textures par voxel  
- optimisation du rendu (uniquement faces visibles)  
- début du système de chunks  
- améliorations de la caméra  
- sauvegarde/chargement du monde  
- génération procédurale basique

🇬🇧  
- per-voxel textures  
- rendering optimization (visible faces only)  
- start of a chunk system  
- improved camera behavior  
- world save/load  
- basic procedural generation

## Notes

🇫🇷  
Projet personnel d’apprentissage, encore en phase expérimentale.

🇬🇧  
Personal learning project, still experimental.
