# 🎮 2D Adventure Game in C (SDL)

## Project Overview

A **2D adventure game** developed in **C** using the **SDL 1.2** library.
The player explores a scrolling world, avoids obstacles and enemies, and must solve **timed riddles (enigmas)** to progress.

---

## ✨ Features

- 🌄 **Scrolling background** with a **day/night animation**
- 🧱 **Pixel-perfect collision** detection using a collision mask
- 🗺️ **Minimap** showing the player's position
- 🧍 **Animated player character** and game entities
- ❓ **Enigmas** with a **countdown timer** and win/lose screens
- 🎵 **Music and sound effects**
- 🖱️ Menus and buttons with hover effects

---

## 🔧 Tech Stack

C · SDL 1.2 · SDL_image · SDL_ttf · SDL_mixer · Makefile · GCC

---

## 🚀 How to Run (Linux)

```bash
# install SDL 1.2 libraries
sudo apt install libsdl1.2-dev libsdl-image1.2-dev libsdl-ttf2.0-dev libsdl-mixer1.2-dev

# build and run a module, e.g. the background
cd Background
make
./pr0
```

---

## 📁 Project Structure

```
Jeu_SDL/
├── Background/         # Scrolling background, day/night, collision
├── enigme/             # Riddle module
├── enigme.animation/   # Animated riddle with timer
├── main.c              # Enemy module demo
├── background.h · entite.h · perso.h · minimap.h · enigme.h
└── es.c                # Enemy animation & movement
```

---

## 👩‍💻 Author

**Ranim Benali** — [GitHub](https://github.com/ranimbenali) · [LinkedIn](https://www.linkedin.com/in/benaliranim/)
