CMAKE_MINIMUM_REQUIRED(VERSION 3.5.1)
PROJECT(cv_tutorial)
FIND_PACKAGE(OpenCV 	REQUIRED )
include_directories ("${OpenCV_INCLUDE_DIRS}")
#Required for uco thinstation. May not be required in your own pc
LINK_LIBRARIES(${OpenCV_LIBS} )
add_executable(Metodos ClaseTiempo.cpp funcionesAuxiliares.cpp principal.cpp sistemaEcuacionesLinuxLocal.o)


 
