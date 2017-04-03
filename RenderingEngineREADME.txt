Rendering Engine README
Author: Roberto Rodriguez

SMFL folders: https://github.com/SFML/SFML

-----------------------------------------------------------------
Application Folder (Engine \ Engine):
	- .dll's
		sfml-audio-2.dll
		sfml-audio-d-2.dll
		sfml-graphics-2.dll
		sfml-graphics-d-2.dll
		sfml-network-2.dll
		sfml-network-d-2.dll
		sfml-stystem-2.dll
		sfml-system-d-2.dll
		sfml-window-2.dll
		sfml-window-d-2.dll

	- images
		Must be in same folder as the application
-----------------------------------------------------------------
VC++ Directories:
	- Release
		~ Include Directories
			SFML-2.4.2\include 

		~ Library Directories
			SFML-2.4.2\lib

	- Debug
		~ Include Directories
			SFML-2.4.2\include
			include\glm\gtx
			include\ode\ode
			ode-0.14\include\ode
			include
			include\GL

		~ Library Directories
			SFML-2.4.2\lib
			lib
			glew-2.0.0
			lib\glut

-----------------------------------------------------------------
C/C++:
	General:
		- Debug
			~ Additional Include Directories
				glm-0.9.8.4\glm\detail
				include

-----------------------------------------------------------------
Linker:
	General:
		- Debug
			~ Additional Library Directories
				SFML-2.4.2\lib
				lib
				lib\Release\Win32
				lib\Release
				lib\lib-vs2015

	Input:
		- Release
			~ Additionnal Dependencies (sfml has to be done in this order)
				sfml-graphics.lib
				sfml-window.lib
				sfml-system.lib

		- Debug
			~ Additional Dependencies  (sfml has to be done in this order)
				sfml-graphics-d.lib
				sfml-window-d.lib
				sfml-system-d.lib
				opengl32.lib
				glew32.lib
				glew32s.lib
				glfw3.lib
				glut32.lib