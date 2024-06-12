# Cub3D

Cub3D is a project from 42 that involves creating a 3D game using the Raycasting technique. This README will guide you through the installation, usage, and understanding of the project.

## Table of Contents

- [Introduction](#introduction)
- [Project Objectives](#project-objectives)
- [Requirements](#requirements)
- [Project Structure](#project-structure)
- [Installation](#installation)
- [Usage](#usage)
- [Features](#features)
- [Contributing](#contributing)
- [Acknowledgments](#acknowledgments)
- [Grade](#grade)

## Introduction

Cub3D is a small 3D game inspired by Wolfenstein 3D, created using the Raycasting technique. The objective of this project is to understand the basics of 3D rendering and game development.

## Project Objectives

The main objectives of this project are:
- To understand and implement Raycasting for 3D rendering.
- To manage player input and movement within a 3D environment.
- To parse and utilize map files to create game levels.
- To implement basic game mechanics such as collision detection.

## Requirements

- GCC or Clang compiler
- Make
- MinilibX (a small graphics library included in the project)
- SDL or other graphical libraries (if used)
- Unix-based system (Linux or macOS)

## Project Structure

```sh
.
├── images/
│   ├── 1.xpm
│   ├── 2.xpm
│   ├── EA.xpm
│   ├── NO.xpm
│   ├── oldEA.xpm
│   ├── oldNO.xpm
│   ├── oldSO.xpm
│   ├── oldWE.xpm
│   ├── SO.xpm
│   └── WE.xpm
├── include/
│   ├── cub3d.h
│   └── cub3d_bonus.h
├── libft/
│   ├── ft_atoi.c
│   ├── ft_bzero.c
│   ├── ft_calloc.c
│   ├── ft_isalnum.c
│   ├── ft_isalpha.c
│   ├── ft_isascii.c
│   ├── ft_isdigit.c
│   ├── ft_isprint.c
│   ├── ft_itoa.c
│   ├── ft_lstadd_back.c
│   ├── ft_lstaddfront.c
│   ├── ft_lstclear.c
│   ├── ft_lstdelone.c
│   ├── ft_lstiter.c
│   ├── ft_lstlast.c
│   ├── ft_lstmap.c
│   ├── ft_lstnew.c
│   ├── ft_lstsize.c
│   ├── ft_memchr.c
│   ├── ft_memcmp.c
│   ├── ft_memcpy.c
│   ├── ft_memmove.c
│   ├── ft_memset.c
│   ├── ft_printf.c
│   ├── ft_printf.h
│   ├── ft_printf_formats.c
│   ├── ft_printfhex.c
│   ├── ft_printf_ptrunin.c
│   ├── ft_putchar_fd.c
│   ├── ft_putendl_fd.c
│   ├── ft_putnbr_fd.c
│   ├── ft_putstr_fd.c
│   ├── ft_split.c
│   ├── ft_strchr.c
│   ├── ft_strdup.c
│   ├── ft_striteri.c
│   ├── ft_strjoin.c
│   ├── ft_strlcat.c
│   ├── ft_strlcpy.c
│   ├── ft_strlen.c
│   ├── ft_strmapi.c
│   ├── ft_strncmp.c
│   ├── ft_strnstr.c
│   ├── ft_strrchr.c
│   ├── ft_strtrim.c
│   ├── ft_substr.c
│   ├── ft_tolower.c
│   ├── ft_toupper.c
│   ├── get_next_line_bonus.c
│   ├── get_next_line_bonus.h
│   ├── get_next_line_utils_bonus.c
│   ├── libft.h
│   └── Makefile
├── Makefile
├── maps/
│   ├── invalid/
│   │   ├── Imap.cub
│   │   ├── map..ecub
│   │   ├── map.cube
│   ├── valid/
│   │   ├── big.cub
│   │   ├── map.cub
│   │   ├── rectac.cub
│   │   └── small.cub
├── src/
│   ├── cleaner.c
│   ├── cub3d.c
│   ├── dda/
│   │   ├── calc_cam_dir.c
│   │   ├── calc_step.c
│   │   ├── dda.c
│   │   ├── dda_checkers.c
│   │   ├── ray_len.c
│   │   └── ray_pos.c
│   ├── events/
│   │   ├── camera_mov.c
│   │   ├── mlx_hooks.c
│   │   └── player_mov.c
│   ├── map/
│   │   ├── checkMap.c
│   │   ├── checkMapUtils.c
│   │   ├── checkMapUtils2.c
│   │   ├── elementsTextures.c
│   │   ├── mapCheck.c
│   │   ├── mapElemtens.c
│   │   └── textureUtils.c
│   ├── mlx_draw/
│   │   ├── draw.c
│   │   ├── draw_background.c
│   │   └── mlx_utils.c
│   └── window/
│   │   ├── game.c
│   │   └── init.c
├── src_bonus/
│   ├── cleaner_bonus.c
│   ├── cub3d_bonus.c
│   ├── dda/
│   │   ├── calc_cam_dir_bonus.c
│   │   ├── calc_step_bonus.c
│   │   ├── dda_bonus.c
│   │   ├── dda_checkers_bonus.c
│   │   ├── ray_len_bonus.c
│   │   └── ray_pos_bonus.c
│   ├── events/
│   │   ├── camera_mov_bonus.c
│   │   ├── mlx_hooks_bonus.c
│   │   └── player_mov_bonus.c
│   ├── map/
│   │   ├── checkMap_bonus.c
│   │   ├── checkMapUtils2_bonus.c
│   │   ├── checkMapUtils_bonus.c
│   │   ├── elementsTextures_bonus.c
│   │   ├── mapCheck_bonus.c
│   │   ├── mapElemtens_bonus.c
│   │   └── textureUtils_bonus.c
│   ├── mlx_draw/
│   │   ├── draw_background_bonus.c
│   │   ├── draw_bonus.c
│   │   ├── mlx_utils_bonus.c
│   │   └── sprite_bonus.c
│   └── window/
│   │   ├── game_bonus.c
│   │   └── init_bonus.c
└── README.md
```

## Installation
To install and run Cub3D, follow these steps:

1. **Clone the Repository**:

```sh
git clone https://github.com/yourusername/cub3d.git
```
2. **Navigate to the project directory**:

```sh
cd cub3d
```

3. **Compile the Project**:

```sh
make
```

## Usage
After successfully compiling the project, you can run the game using:

```sh
./cub3D path_to_map_file.cub
```

## Controls
- W : Move forward
- S : Move backward
- A : Move left
- D : Move right
- Left Arrow : Rotate view left
- Right Arrow : Rotate view right
- ESC : Exit the game


## Features
- Basic 3D rendering using Raycasting
- Player movement and rotation
- Simple map parsing
- Basic collision detection


## Contributing
Contributions are what make the open source community such an amazing place to learn, inspire, and create. Any contributions you make are greatly appreciated.

If you have a suggestion that would make this better, please fork the repo and create a pull request. You can also simply open an issue with the tag "enhancement".

- Fork the Project
- Create your Feature Branch (git checkout -b feature/AmazingFeature)
- Commit your Changes (git commit -m 'Add some AmazingFeature')
- Push to the Branch (git push origin feature/AmazingFeature)
- Open a Pull Request


## Acknowledgments
- 42 School
- Wolfenstein 3D
- Raycasting Tutorial

 
## Grade
- Norminette: Ok!
- Grade: 115/100

---

Happy coding!
