# (C) Copyright 2016 Hewlett Packard Enterprise Development LP
#
#  Licensed under the Apache License, Version 2.0 (the "License"); you may
#  not use this file except in compliance with the License. You may obtain
#  a copy of the License at
#
#       http://www.apache.org/licenses/LICENSE-2.0
#
#  Unless required by applicable law or agreed to in writing, software
#  distributed under the License is distributed on an "AS IS" BASIS, WITHOUT
#  WARRANTIES OR CONDITIONS OF ANY KIND, either express or implied. See the
#  License for the specific language governing permissions and limitations
#  under the License.

cmake_minimum_required (VERSION 2.8)

project ("supportability_cli")

set (INCL_DIR ${CMAKE_SOURCE_DIR}/include)
set (LIBSUPPORTABILITYCLI supportability_cli)

# This option is passed by build system.
OPTION( CPU_LITTLE_ENDIAN "Specifies CPU architecture is Little-Endian" OFF )

# Define compile flags
set(CMAKE_C_FLAGS "${CMAKE_C_FLAGS} -std=gnu99 -Wall -Werror")


add_definitions(-DHAVE_CONFIG_H -DHAVE_SOCKLEN_T)

# Rules to locate needed libraries
include(FindPkgConfig)
pkg_check_modules(OVSCOMMON REQUIRED libovscommon)
pkg_check_modules(OPSCLI REQUIRED ops-cli)

include_directories (${INCL_DIR}
                     ${PROJECT_SOURCE_DIR}
                     ${OVSCOMMON_INCLUDE_DIRS}
                     ${OPSCLI_INCLUDE_DIRS}
                    )

# CLI libraries source files
set (SOURCES_CLI ${PROJECT_SOURCE_DIR}/show_tech_vty.c
                 ${PROJECT_SOURCE_DIR}/../showtech/showtech.c
                 ${PROJECT_SOURCE_DIR}/show_events_vty.c
                 ${PROJECT_SOURCE_DIR}/show_core_dump_vty.c
                 ${PROJECT_SOURCE_DIR}/core_dump.c
                 ${PROJECT_SOURCE_DIR}/diag_dump_vty.c
                 ${PROJECT_SOURCE_DIR}/show_vlog_vty.c
                 ${PROJECT_SOURCE_DIR}/../featuremapping/feature_mapping.c
                 ${PROJECT_SOURCE_DIR}/supportability_vty.c
                 ${PROJECT_SOURCE_DIR}/../supportability_utils.c
    )

add_library (${LIBSUPPORTABILITYCLI} SHARED ${SOURCES_CLI})


target_link_libraries(${LIBSUPPORTABILITYCLI} ${OVSCOMMON_LIBRARIES} -lyaml -lsystemd)



# Installation
install(TARGETS ${LIBSUPPORTABILITYCLI}
        LIBRARY DESTINATION lib/cli/plugins
       )
