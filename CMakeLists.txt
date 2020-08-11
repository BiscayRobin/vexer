cmake_minimum_required(VERSION 3.9)
project(vexer VERSION 1.0.0 DESCRIPTION "vector library for C code")
include(GNUInstallDirs)

include_directories(${CMAKE_CURRENT_SOURCE_DIR}/inc)
add_library(vexer SHARED
	src/vector.c
	inc/vector.h
)
set_target_properties(vexer PROPERTIES 
VERSION ${PROJECT_VERSION}
PUBLIC_HEADER inc/vector.h
)
configure_file(vexer.pc.in vexer.pc @ONLY)
target_include_directories(vexer PRIVATE .)
install(TARGETS vexer
	LIBRARY DESTINATION ${CMAKE_INSTALL_LIBDIR}
	PUBLIC_HEADER DESTINATION ${CMAKE_INSTALL_INCLUDEDIR}
)
install(FILES ${CMAKE_BINARY_DIR}/vexer.pc
	DESTINATION ${CMAKE_INSTALL_DATAROOTDIR}/pkgconfig
)