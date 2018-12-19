CMAKE_MINIMUM_REQUIRED(VERSION 3.0)
PROJECT(metodosOrdenacion)
#Required for uco thinstation. May not be required in your own pc
SET(CMAKE_CXX_STANDARD 11)
SET(CMAKE_CXX_FLAGS " -D_GLIBCXX_USE_CXX11_ABI=0 -m32")
add_executable(P5 principal.cpp funcionesAuxiliares.cpp sistemaMonetario.cpp sistemaEcuaciones.cpp ClaseTiempo.cpp estadistica.cpp)