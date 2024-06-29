# So_long
A very simple 2D game - part of 42 school common core cursus

This was my first (very moderately) big project in C, and while the code is not the most elegant I don't regret the sleepless nights spent assembling it with sticks and duct tape.

![img](SL_screenshot.png?raw=true)


## Goal
  - Touch all the planets to terraform them and escape the system.
  - Exit is only accessible once all the planets have been touched.
  - Avoid or kill aliens! The red portals are their spawn points.
  - One red portal will become blue once you can escape: this is the exit.

## Features
  - Real time gameplay
  - Semi procedural background (map size dependent)
  - Diagonal movements
  - Killable and Respawning ennemies
  - HPs on HUD
  - BIG LASER GOES BZZZZZZZT (no sound though)

## Controls:
  - Move with WASD
  - Fire the laser with space

## Compile and run: 
```bash
  make ball
  ./so_long_bonus maps/map_bonus.ber

```
## Acknowledgements

Huge thanks for these creators and their cool textures: 

 - [Pixel Planets Generator](https://deep-fold.itch.io/pixel-planet-generator)
 - [Void Ship](https://foozlecc.itch.io/void-main-ship)
