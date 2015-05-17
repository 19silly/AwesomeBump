
![alt tag](https://github.com/kmkolasinski/AwesomeBump/blob/master/Sources/resources/githubimage3.jpg)
AwesomeBump  Pi 
===========

AwesomeBump is a free and open source program written using Qt library designed to generate normal, height, specular or ambient occlusion textures from a single image. Since the image processing is done in 99% on GPU the program runs very fast and all the parameters can be changed in real time. AB was made to be a new alternative to known gimp plugin called Insane Bump or commercial tool: Crazy Bump. Since 3.0 AB supports the PBR lightning model (roughness and metallic textures were introduced).

Feel free to contact me if you find any bugs and problems: support@awesomebump.besaba.com

If you want to fix or improve something please fork my repo and send me the pull-request with changes. 

AB is using tinyobjloader for loading the OBJ files: https://github.com/syoyo/tinyobjloader

Cube maps textures were taken from Humus page [link](http://www.humus.name/index.php?page=Textures) 

Project Webpage: http://awesomebump.besaba.com/

### Download binaries from [here](https://github.com/kmkolasinski/AwesomeBump/releases) (.zip or tar.gz files). 



INSTALLATION:
============
## Since version 3.0 
Steps are almost the same as for earlier versions.
See the [pdf ](https://github.com/kmkolasinski/AwesomeBump/releases/download/BuildingAB/BuildingInstruction.pdf) for instructions.



## For versions older than 3.0.

0. Video tutorial: https://www.youtube.com/watch?v=R-WgHserrS0
1. In order to build AwesomeBump you will need to have qt-sdk installed: http://www.qt.io/download/ 
2. Download the sourcecode of AB from github and unzip it. Run Qt then open a new project using the AwesomeBump.pro file (located in AB source code folder.). 
3. Setup the build path and run path (in project build settings panel) and compile the project (remember that your graphics card has to support at least openGL 4.0). Compilation step will take some time. Run the program. In case of problems see the log.txt file.
4. I hope you will like it :)

## Command-line instructions:

1.) Open terminal and unzip or untar downloaded source code.

2.) Enter to created folder

3.) Open linuxBuildScript.sh file and set the propper Qt5 path. Save and close.

4.) Run script with command: sh linuxBuildScript.sh

5.) If everything gone well AB should start after compilation process. See Bin/ folder. There should be an AwesomeBump file now.

### OpenGL 3.30 support
You can now build AB to run all openGL instructions with 3.30 compatibility (note that tessellation will not work with 3.30). See [pdf ](https://github.com/kmkolasinski/AwesomeBump/releases/download/BuildingAB/BuildingInstruction.pdf) file and "Step 8" for more datails. Basicaly you just have to add "CONFIG+=release_gl330" command in the qmake settings in order to build 3.30  supported version of AB. 

New in version 4.0  
===========
1) Grunge texture added

2) Angle correction algorithm added when converting from Base map.

3) And some minor fixes.

New in version Pi (3.14) 
===========
1) Added tessellation grid preview button

2) Added normal map mixer tool

3) Font size can be channged

4) DOF - filter in 3D window added

5) Mipmap levels in "base map to others" tool

6) materials texture tool added

7) Now all images work with: drag and drop to materials, copy from clipboard, copy to clipboard

8) Project manager filter tool

9) Mesh can be dragged to the 3D widget

10) In "bump mapping" roughness texture is taken as glossines texture

11) Apply UV transformation button added

12) Plus some bug fixes and minor changes.

New in version 3.0 + update 3.0.2 (29.03.15)
===========
1) Added error Logger

2) Remove lightning with new AO cancellation feature added.

3) Rouhness and metallic textures are now supported (PBR shading in action). Additionally new tools (noise filter and color picker) to manipulate these textures are available.

4) Color Hue slider added.

5) Input image feature for most of textures are available now.

6) Selective blur feature (height texture only) is now available.

7) And other important changes...

8) Thanks to David for new cool models :)

9) Update 3.0.1: Improved seamless alhorithms, improved GUI, mouse loop added

10) Update 3.0.2: Added bloom effect

New in version 2.1
===========
1) Added support for 3D models (only OBJ format)

2) Simple project manager

3) And few less important.


New in version 2.0:
============
1) Slightly redesigned GUI: Tiling/UV methods, General Settings and 3D
   preview sliders are now separated into different tabs.
   
2) Added short explanation about most important algorithms in AB. See ShortAbout.pdf file.

3) New random tiling algorithm was added. Which allow to generate 
   infinite number of seamless textures.
   
4) New perspective mode - image can be now stretched along x and y axis,
   which is useful during the perspective manipulation.
   
5) Height calculator tool was added. Now the depth of the Normal texture
   can be controlled based on physical dimensions.
   
6) Size of the texture can be changes at run-time.

7) Gray Scale manipulator - now you can choose what weights are used to
   convert image to Gray scale.
   
8) Colour levelling tool was added. This can be used e.g. to make flat
   surfaces.
   
9) Now the normal image is by default attached to height texture, which
   means any change of height will affect the normals.
   

Minor changes:
- Unused button in AO tab was removed.
- Fixed problem with "cannot load image".
- Medium detail algorithm changed - it should give better results.
- Redefined the normal step slider, now it has more intuitive usage.
- You can choose your preferred GUI style.
- add many others small improvements.


New in version 1.0:
============
1) log.txt file is created during each run. This file contains
   information about possible errors and program outputs. In case some
   problems (eq. GL version incompatibility) see this file.
   
2) New camera.cpp class introduced in order to improve 3D image
   manipulation. Right button can be used to pan 3D plane. Left to rotate
   camera around paned point.
   
3) Now 2D image can be dragged with mouse right button  and zoomed with
   mouse wheel.
   
4) New perspective tool funcionality added. You can stretch each corner
   of 2D image in order to correct and align image. Reset transform button
   restore settings.
   
5)  Added support for TGA files (import and export).



