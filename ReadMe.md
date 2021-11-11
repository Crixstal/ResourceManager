# **Resource Manager**

## **Summary**

- [Description](##Description)
- [Informations](##Informations)
- [Known issues](##Known%20issues)
- [Work done](##Work)
- [Third-party programs and libraries](##Third-party%20programs%20and%20libraries)
- [References](##References)

<br>

## **Description**

The goal is to parallelize the loading of resources by avoiding deadlocks and data-races.
It will be necessary to understand the memory alignment as well as to synchronize the operations to have the best result.

<br>

## **Informations**

The build and the resources can be found in the zip file "Build+Resources" under the GOLD release.

The program runs in Debug or Release, platform x64. 
You need to put the files:
- irrKlang.dll 
- ikpMP3.dll
- ikpFlac.dll <br>
<div style="text-align:left">
in the folder x64/Release (or x64/Debug)<br><br>

The resources (obj, textures, mtl, etc) are in the zip file on sirius: GP2_MEHALIN_M/BIN/resources.

In monothreading, we obtain an average load time of the main scene of 9.30 seconds for 10 consecutive builds (1second to display the main menu) in Release. <br>
In multithreading, we obtain an average load time of the main scene of 4.22 seconds for 10 consecutive builds in Release.

<br>

## **Known issues**

Be careful to use your NVIDIA graphic card or the engine will lag.
Sometimes the buttons texture isn't display.

<br>

## **Work done**

- threadpool
- multithread textures
- multithread meshes

<br>

## **Third-party programs and libraries**

irrKlang
---
https://www.ambiera.com/irrklang/

stb
---
https://github.com/nothings/stb

GLFW
---
https://www.glfw.org/

Glad
---
https://glad.dav1d.de/

<br>

## **References**

OpenGL:
---
- Gives the different functions of OpenGL:
http://docs.gl/
- Ditto:
https://www.khronos.org/opengl/

C++:
---
- C++ references: https://en.cppreference.com/
- Thread: http://www.cplusplus.com/reference/thread/thread/