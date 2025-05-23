<h1 style="text-align: center;">Raytracer from scratch</h1> 

---------------------------------------------------------------------------------------------------

### Resources: 

* [_Ray Tracing in One Weekend_](https://raytracing.github.io/books/RayTracingInOneWeekend.html).

* [_Cherno Ray tracing_](https://www.youtube.com/watch?v=gfW1Fhd9u9Q&list=PLlrATfBNZ98edc5GshdBtREv5asFW3yXl).

* [_Graphics Programming Compendium_](https://graphicscompendium.com/index.html).
---------------------------------------------------------------------------------------------------
### Features: 
1. Antialising :white_check_mark:
2. Diffuse Materials :white_check_mark:
3. Metal :white_check_mark:
4. Dielectrics :white_check_mark:
5. Positionable Camera :white_check_mark:
6. Defocus Blur :white_check_mark:

----------------------------------------------------------------------------------------------------
### Dependencies
* [Eigen](https://eigen.tuxfamily.org/dox/index.html) _(version 3.4)_.

----------------------------------------------------------------------------------------------------
### Building the project
 If you wish to build the provided source, this project uses CMake. To build, go to the root of the project directory and run the following commands to create the debug version of every executable:

    $ cmake -B build
    $ cmake --build build

On Windows, you can build either `debug` (the default) or `release` (the optimized version). To specify this, use the `--config <debug|release>` option.

----------------------------------------------------------------------------------------------------
### Running the program

ToDo

 ----------------------------------------------------------------------------------------------------
 <p align="center">
 <img center src="images/Render_Final_Scene_1200_spp500_d50.png" width=600 height=337/> 
 </p>
