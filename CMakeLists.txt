##---------------------------------------------------------------------------
## Author:      Pavel Saviankou
##***************************************************************************
## *   Copyright (C) 2016 by Pavel Saviankou                                 *
## *   This program is free software; you can redistribute it and/or modify  *
## *   it under the terms of the GNU General Public License as published by  *
## *   the Free Software Foundation; either version 2 of the License, or     *
## *   (at your option) any later version.                                   *
## *                                                                         *
## *   This program is distributed in the hope that it will be useful,       *
## *   but WITHOUT ANY WARRANTY; without even the implied warranty of        *
## *   MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the         *
## *   GNU General Public License for more details.                          *
## *                                                                         *
## *   You should have received a copy of the GNU General Public License     *
## *   along with this program; if not, write to the                         *
## *   Free Software Foundation, Inc.,                                       *
## *   51 Franklin Street, Fifth Floor, Boston, MA 02110-1301,  USA.             *
## ***************************************************************************

# define minimum cmake version
CMAKE_MINIMUM_REQUIRED(VERSION 2.6.2)
# This should be 2.8.0 to have FindGTK2 module
IF (COMMAND cmake_policy)
  CMAKE_POLICY(SET CMP0003 OLD)
  CMAKE_POLICY(SET CMP0005 OLD)
  CMAKE_POLICY(SET CMP0011 OLD)
ENDIF (COMMAND cmake_policy)

PROJECT(admiralty_tide_tables_pi)

SET(PACKAGE_NAME admiralty_tide_tables_pi)

SET(PACKAGE_NAME admiralty_tide_tables_pi)
SET(VERBOSE_NAME "A.T.T. Calculation plugin")
SET(TITLE_NAME ATT)
SET(CPACK_PACKAGE_CONTACT "Pavel Saviankou ")
SET(PLUGIN_SOURCE_DIR ..)
MESSAGE (STATUS "*** Building ${PACKAGE_NAME} ***")
SET(BUNDLE_DATA TRUE)

INCLUDE( VERSION.cmake )
SET(PLUGIN_VERSION "${PLUGIN_VERSION_MAJOR}.${PLUGIN_VERSION_MINOR}.${PLUGIN_VERSION_PATCH}" )

SET(VERSION_MAJOR ${PLUGIN_VERSION_MAJOR})
SET(VERSION_MINOR "${PLUGIN_VERSION_MINOR}")
SET(VERSION_DATE ${PLUGIN_VERSION_DATE})

INCLUDE("cmake/PluginConfigure.cmake")



#SET(CMAKE_BUILD_TYPE Debug)

IF (PREFIX)
	SET(CMAKE_INSTALL_PREFIX ${PREFIX})
ENDIF (PREFIX)

SET(PARENT opencpn)
SET(PREFIX_BIN bin)
SET(PREFIX_INCLUDE include)
SET(PREFIX_DATA share)
SET(PREFIX_PARENTDATA ${PREFIX_DATA}/${PARENT})

INCLUDE_DIRECTORIES(${CMAKE_SOURCE_DIR}/include ${CMAKE_SOURCE_DIR}/src)

# require proper c++
#ADD_DEFINITIONS( "-Wall -ansi -pedantic -Wno-variadic-macros" )
#TODO: Should we use  -fno-stack-protector
#  IF NOT DEBUGGING CFLAGS="-O2 -march=native"
IF(NOT WIN32)
 ADD_DEFINITIONS( "-Wall -g -fexceptions -fvisibility=hidden" )

 IF(NOT APPLE)
  SET(CMAKE_SHARED_LINKER_FLAGS "-Wl,-Bsymbolic")
 ELSE(NOT APPLE)
  SET(CMAKE_SHARED_LINKER_FLAGS "-Wl")
 ENDIF(NOT APPLE)

ENDIF(NOT WIN32)

# Add some definitions to satisfy MS
IF(WIN32)
    ADD_DEFINITIONS(-D__MSVC__)
    ADD_DEFINITIONS(-D_CRT_NONSTDC_NO_DEPRECATE -D_CRT_SECURE_NO_DEPRECATE)
ENDIF(WIN32)


SET(wxWidgets_USE_LIBS base core net xml html adv)
SET(BUILD_SHARED_LIBS TRUE)
FIND_PACKAGE(wxWidgets REQUIRED)

INCLUDE(${wxWidgets_USE_FILE})

FIND_PACKAGE(Gettext REQUIRED)

# For convenience we define the sources as a variable. You can add 
# header files and cpp/c files and CMake will sort them out


SET(ATT_SRC
 		src/ATTCalculation.cpp
 		src/ATTCalculation.h
 		src/ATTDialog.cpp
 		src/ATTDialog.h
 		src/ATTDirectoryLister.h
 		src/ATTPortFactory.cpp
 		src/ATTPortFactory.h
 		src/ATTSecondaryPort.cpp
 		src/ATTSecondaryPort.h
 		src/ATTServices.cpp
 		src/ATTServices.h
 		src/ATTStandardPort.cpp
 		src/ATTStandardPort.h
 		src/ATTTime.cpp
 		src/ATTTime.h
 		src/ATTTimeValidator.cpp
 		src/ATTTimeValidator.h
 		src/att_pi.cpp
 		src/tool_icon.cpp
 		src/tool_icon.h
                src/att_pi.h
 	)


ADD_LIBRARY(${PACKAGE_NAME} SHARED ${ATT_SRC}  )

IF(WIN32)
  SET(OPENCPN_IMPORT_LIB "../../../${CMAKE_CFG_INTDIR}/${PARENT}")
  TARGET_LINK_LIBRARIES( ${PACKAGE_NAME} ${OPENCPN_IMPORT_LIB} )
  ADD_DEPENDENCIES(${PACKAGE_NAME} ${PARENT})
ENDIF(WIN32)

TARGET_LINK_LIBRARIES( ${PACKAGE_NAME} ${wxWidgets_LIBRARIES} )

IF(UNIX)
INSTALL(TARGETS ${PACKAGE_NAME} RUNTIME LIBRARY DESTINATION ${PREFIX_PARENTDATA}/plugins)
ENDIF(UNIX)

IF(WIN32)
INSTALL(TARGETS ${PACKAGE_NAME} RUNTIME DESTINATION "plugins")
ENDIF(WIN32)
 	  	 
INCLUDE("cmake/PluginInstall.cmake")
INCLUDE("cmake/PluginLocalization.cmake")
INCLUDE("cmake/PluginPackage.cmake")
