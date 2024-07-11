# generated from ament/cmake/core/templates/nameConfig.cmake.in

# prevent multiple inclusion
if(_njord_tasks_CONFIG_INCLUDED)
  # ensure to keep the found flag the same
  if(NOT DEFINED njord_tasks_FOUND)
    # explicitly set it to FALSE, otherwise CMake will set it to TRUE
    set(njord_tasks_FOUND FALSE)
  elseif(NOT njord_tasks_FOUND)
    # use separate condition to avoid uninitialized variable warning
    set(njord_tasks_FOUND FALSE)
  endif()
  return()
endif()
set(_njord_tasks_CONFIG_INCLUDED TRUE)

# output package information
if(NOT njord_tasks_FIND_QUIETLY)
  message(STATUS "Found njord_tasks: 0.0.0 (${njord_tasks_DIR})")
endif()

# warn when using a deprecated package
if(NOT "" STREQUAL "")
  set(_msg "Package 'njord_tasks' is deprecated")
  # append custom deprecation text if available
  if(NOT "" STREQUAL "TRUE")
    set(_msg "${_msg} ()")
  endif()
  # optionally quiet the deprecation message
  if(NOT ${njord_tasks_DEPRECATED_QUIET})
    message(DEPRECATION "${_msg}")
  endif()
endif()

# flag package as ament-based to distinguish it after being find_package()-ed
set(njord_tasks_FOUND_AMENT_PACKAGE TRUE)

# include all config extra files
set(_extras "")
foreach(_extra ${_extras})
  include("${njord_tasks_DIR}/${_extra}")
endforeach()
