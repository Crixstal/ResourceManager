# **Resource Manager by Manon Méhalin**

## **Summary**

- [Description](##Description)
- [Informations](##Informations)
- [Known issues](##Known%20issues)
- [Work](##Work)
- [Annexes](##Annexes)
- [Third-party programs and libraries](##Third-party%20programs%20and%20libraries)
- [References](##References)

## **Description**

The goal is to parallelize the loading of resources by avoiding deadlocks and data-races.
It will be necessary to understand the memory alignment as well as to synchronize the operations to have the best result.

## **Informations**

The program runs in Debug or Release, platform x64. 
You need to put the files:
- irrKlang.dll 
- ikpMP3.dll
- ikpFlac.dll <br>
<div style="text-align:left">
in the folder x64/Release (or x64/Debug), they can be found on sirius: GP2_MEHALIN_M/BIN. <br><br>

The resources (obj, textures, mtl, etc) are in the zip file on sirius: GP2_MEHALIN_M/BIN/resources.

In monothreading, we obtain an average load time of the main scene of 9.30seconds for 10 consecutive builds (1second to display the main menu) in Release.

## **Known issues**

Be careful to use your NVIDIA graphic card or the engine will lag.
Sometimes the buttons texture isn't display.
If the game is closed too soon (not in the main menu) there is some leaks.

## **Work**

Done:
---
- threadpool
- multithread textures
- multithread meshes

## **Annexes**

Link to the UML:
https://miro.com/app/board/o9J_lxucykI=/ <br>
It's a simplier version which only shows what have been changed

You can find the UML of the whole engine here:
https://miro.com/welcomeonboard/lOMYMf0qwZh91frzycgVN5734rGQn5auxxdjySUvD567BnYCpg9ax7DVqhvT4jLA


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