# Against The Ants Game

<img src="https://user-images.githubusercontent.com/73097560/115834477-dbab4500-a447-11eb-908a-139a6edaec5c.gif">

## Description
Against The Ants is a type of tower defense game where players strategically place obstacles to prevent waves of ants from stealing pizza and bringing it back to their colony. The game is built using SDL2 and C++.

<img src="https://user-images.githubusercontent.com/73097560/115834477-dbab4500-a447-11eb-908a-139a6edaec5c.gif">

## Installation

### System Requirements
- Operating System: Windows
- Integrated Development Environment (IDE): Visual Studio 2022

### Instructions
1. **Clone the Repository:**
   ```
   git clone https://github.com/DauDucHieu/AgainstTheAnts.git
   ```

2. **Open Project in Visual Studio 2022:**
   - Navigate to the directory where you cloned the repository.
   - Open the `Against the Ants.sln` file in Visual Studio 2022.

3. **Build and Run:**
   - Choose the build configuration (Debug/Release) and platform (x64) that suits your environment.
   - Press `Ctrl + F5` or click on the "Start" button in Visual Studio to build and run the game.

<img src="https://user-images.githubusercontent.com/73097560/115834477-dbab4500-a447-11eb-908a-139a6edaec5c.gif">

## Gameplay

### Game Rules - Instructions
- Place obstacles strategically on the game board using mouse clicks.
- Ants have diffrent behaviours to reach the pizza. Stop them by strategically placing obstacles to block their path.
- The game ends when the pizza is stolen by the ants or you can protect the pizza after a time range.

### Game Entities
#### Ants
|               | ****Moving****             | ****HP Level**** |****Speed Level**** | ****Special Skill**** |
|---------------|----------------------------|------------------|--------------------| ----------------------| 
| **Normal Ant**| Random Move                | Average          | Average            |                       |
| **Speedy Ant**| Random Move                | Low              | High               |                       |
| **Smart Ant** | Random Move / Path Finding | Low              | Average            | If Pizza is not carried by other ants, use the BFS algorithm to find a path to the pizza without colliding with traps. <br>Else Random Move |
### Traps
|               |   Effect           | Active Time|
|---------------|--------------------|------------|
| **Pond**      | Slowdown Ants      | High       |
| **Honey**     | Heal HP Ants       | High       |
| **Black Hole**| Kill Ants directly | Low        |

### Game Mechanics
- Random Spawn Ants after time
- Random Set Appearence Rate of Traps

### Algorithms
- BFS (Breadth-first search): PathFinding

<img src="https://user-images.githubusercontent.com/73097560/115834477-dbab4500-a447-11eb-908a-139a6edaec5c.gif">

## References
- SDL2: [SDL Wiki](https://wiki.libsdl.org/SDL2/Tutorials), [UET courses](https://courses.uet.vnu.edu.vn/pluginfile.php/384113/mod_resource/content/1/Lec07-08-SDL.pdf)
- BFS: [Wikipedia-Vi](https://vi.wikipedia.org/wiki/T%C3%ACm_ki%E1%BA%BFm_theo_chi%E1%BB%81u_r%E1%BB%99ng), [Wikipedia-En](https://en.wikipedia.org/wiki/Breadth-first_search)
- Idea inspiration: [Game "Against the Ants" in Google Play Store](https://play.google.com/store/apps/details?id=com.themaniacs.againsttheants&hl=vi&gl=US)

## Author
- Name: [Dau Duc Hieu](https://github.com/DauDucHieu)
- Email: dauduchieu.ddh775@gmail.com

<img src="https://user-images.githubusercontent.com/73097560/115834477-dbab4500-a447-11eb-908a-139a6edaec5c.gif">

## More
*You also can download this project in Google Drive [Link](https://drive.google.com/file/d/1A6TAlfIlRj7oRSwX45rOxVCk-K27auVD/view?usp=sharing)*
