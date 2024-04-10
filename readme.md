# Cub3D

<!-- Improved compatibility of back to top link: See: https://github.com/othneildrew/Best-README-Template/pull/73 -->
<a name="readme-top"></a>
<!--
*** Thanks for checking out the Best-README-Template. If you have a suggestion
*** that would make this better, please fork the repo and create a pull request
*** or simply open an issue with the tag "enhancement".
*** Don't forget to give the project a star!
*** Thanks again! Now go create something AMAZING! :D
-->



<!-- PROJECT SHIELDS -->
<!--
*** I'm using markdown "reference style" links for readability.
*** Reference links are enclosed in brackets [ ] instead of parentheses ( ).
*** See the bottom of this document for the declaration of the reference variables
*** for contributors-url, forks-url, etc. This is an optional, concise syntax you may use.
*** https://www.markdownguide.org/basic-syntax/#reference-style-links
-->
[![LinkedIn][linkedin-shield]][linkedin-url]

<!-- PROJECT LOGO -->
<br />
<div align="center">
  <a href="https://github.com/iel-amra/So_long">
    <img src="https://github.com/iel-amra/Cub3D/blob/main/Cub3D.png?raw=true" alt="Logo" width="400" height="400">
  </a>

  <h3 align="center">Cub3D - The raycaster</h3>

  <p align="center">
    A simple demo of the raycasting algorithm
  </p>
</div>



<!-- ABOUT THE PROJECT -->
## About The Project

Cub3D is a project at 42, a programming school, focusing on raycasting technology to create a simple 3D game reminiscent of the classic Wolfenstein 3D. The objective is to render a maze in a 3D perspective using raycasting techniques, where the player can navigate through the maze and interact with the environment.


![Product Name Screen Shot][product-screenshot]

### Features
* Rendering of a 3D maze using raycasting.
* Textured walls and sprites.
* Player movement and collision detection.
* Ability to rotate the camera.
* Possibility to create or customize a map.

### Rules
* The program should read a scene description from a .cub file.
* The scene description includes specifications for the resolution, textures, colors, and map layout.
* The player should be able to move within the map using arrow keys, and rotate the view using the mouse or the left and right arrow keys.

<p align="right">(<a href="#readme-top">back to top</a>)</p>



<!-- GETTING STARTED -->
## Getting Started

Cub3D was developed and tested only on ubuntu, but should work well on other debian based distribution

### Prerequisites

<p>MiniLibX for Linux requires <code class="language-plaintext highlighter-rouge">xorg</code>, <code class="language-plaintext highlighter-rouge">x11</code> and <code class="language-plaintext highlighter-rouge">zlib</code>, therefore you will need to install the following dependencies: <code class="language-plaintext highlighter-rouge">xorg</code>, <code class="language-plaintext highlighter-rouge">libxext-dev</code> and <code class="language-plaintext highlighter-rouge">zlib1g-dev</code>. Installing these dependencies on Ubuntu can be done as follows:</p>

```
sudo apt-get update && sudo apt-get install xorg libxext-dev zlib1g-dev libbsd-dev
```

### Installation

1. Clone the repo
   ```
   git clone git@github.com:iel-amra/Cub3D.git
   ```
2. Enter the Cub3D folder and compile
   ```
   cd Cub3D && make
   ```

That's it ! Cub3D is now installed on your machine.

<p align="right">(<a href="#readme-top">back to top</a>)</p>



<!-- USAGE EXAMPLES -->
## Usage

You can launch any map you want with the following syntax :
```
./cub3D [path_to_map]
```

To start the first map of the game, enter the following command in your terminal :
```
./cub3D maps/normal.cub
```

Keys :
* Deplacement : W,A,S,D
* Camera : The arrow keys and mouse cursor
* Exit the game : Escape

<p align="right">(<a href="#readme-top">back to top</a>)</p>



## Map creation

To build a map, create a file with a .ber extension and fill it with the following characters :
- 0 : Air
- 1 : Walls
- N, S, E, W : Player starting position and orientation (Only 1)
- E : Exit (At least 1)

The map needs to be closed, else the game won't start, and it's extension needs to be .cub
For example the following file :

```
1111111
1P0C0E1
1111111
```
Gives the following map :

<img src="https://github.com/iel-amra/Cub3D/blob/main/img/screenshot_map.png?raw=true" alt="map-screenshot" width="500"/>

<p align="right">(<a href="#readme-top">back to top</a>)</p>



<!-- CONTACT -->
## Contact

Ihab El amrani - [Linkedin](https://www.linkedin.com/in/ihab-el-amrani) - iel-amra@student.42lyon.fr

Project Link: [https://github.com/iel-amra/So_long](https://github.com/iel-amra/So_long)

My github : [https://github.com/iel-amra](https://github.com/iel-amra)

<p align="right">(<a href="#readme-top">back to top</a>)</p>



<!-- MARKDOWN LINKS & IMAGES -->
<!-- https://www.markdownguide.org/basic-syntax/#reference-style-links -->
[linkedin-shield]: https://img.shields.io/badge/-LinkedIn-black.svg?style=for-the-badge&logo=linkedin&colorB=555
[linkedin-url]: https://www.linkedin.com/in/ihab-el-amrani
[product-screenshot]: https://github.com/iel-amra/Cub3D/blob/main/screenshot.png?raw=true
[map-screenshot]: https://github.com/iel-amra/So_long/blob/main/img/screenshot_map.png?raw=true