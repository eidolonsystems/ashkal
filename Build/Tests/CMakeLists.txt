find_package(Qt5Widgets REQUIRED)
file(GLOB source_files ../../Source/Tests/*.cpp)
add_executable(ashkal_tester ${source_files})
if(UNIX)
  target_link_libraries(ashkal_tester
    debug ${QT_GIF_LIBRARY_DEBUG_PATH}
    optimized ${QT_GIF_LIBRARY_OPTIMIZED_PATH}
    debug ${QT_XCB_PLATFORM_LIBRARY_DEBUG_PATH}
    optimized ${QT_XCB_PLATFORM_LIBRARY_OPTIMIZED_PATH}
    debug ${QT_XCB_PLUGIN_LIBRARY_DEBUG_PATH}
    optimized ${QT_XCB_PLUGIN_LIBRARY_OPTIMIZED_PATH})
  if(EXISTS ${QT_LINUX_ACCESSIBILITY_SUPPORT_LIBRARY_DEBUG_PATH})
    target_link_libraries(ashkal_tester
      debug ${QT_LINUX_ACCESSIBILITY_SUPPORT_LIBRARY_DEBUG_PATH}
      optimized ${QT_LINUX_ACCESSIBILITY_SUPPORT_LIBRARY_OPTIMIZED_PATH})
  endif()
  target_link_libraries(ashkal_tester
    debug ${QT_SERVICE_SUPPORT_LIBRARY_DEBUG_PATH}
    optimized ${QT_SERVICE_SUPPORT_LIBRARY_OPTIMIZED_PATH}
    debug ${QT_THEME_LIBRARY_DEBUG_PATH}
    optimized ${QT_THEME_LIBRARY_OPTIMIZED_PATH}
    debug ${QT_DBUS_LIBRARY_DEBUG_PATH}
    optimized ${QT_DBUS_LIBRARY_OPTIMIZED_PATH}
    debug ${QT_XML_LIBRARY_DEBUG_PATH}
    optimized ${QT_XML_LIBRARY_OPTIMIZED_PATH})
endif()
target_link_libraries(ashkal_tester library
  debug ${QT_GIF_LIBRARY_DEBUG_PATH}
  optimized ${QT_GIF_LIBRARY_OPTIMIZED_PATH}
  debug ${QT_SVG_ICON_PLUGIN_LIBRARY_DEBUG_PATH}
  optimized ${QT_SVG_ICON_PLUGIN_LIBRARY_OPTIMIZED_PATH}
  debug ${QT_SVG_LIBRARY_DEBUG_PATH}
  optimized ${QT_SVG_LIBRARY_OPTIMIZED_PATH}
  debug ${QT_WIDGETS_LIBRARY_DEBUG_PATH}
  optimized ${QT_WIDGETS_LIBRARY_OPTIMIZED_PATH}
  debug ${QT_FONT_LIBRARY_DEBUG_PATH}
  optimized ${QT_FONT_LIBRARY_OPTIMIZED_PATH}
  debug ${QT_GUI_LIBRARY_DEBUG_PATH}
  optimized ${QT_GUI_LIBRARY_OPTIMIZED_PATH}
  debug ${QT_PNG_LIBRARY_DEBUG_PATH}
  optimized ${QT_PNG_LIBRARY_OPTIMIZED_PATH}
  debug ${QT_EVENT_LIBRARY_DEBUG_PATH}
  optimized ${QT_EVENT_LIBRARY_OPTIMIZED_PATH}
  debug ${QT_ACCESS_LIBRARY_DEBUG_PATH}
  optimized ${QT_ACCESS_LIBRARY_OPTIMIZED_PATH}
  debug ${QT_HBNG_LIBRARY_DEBUG_PATH}
  optimized ${QT_HBNG_LIBRARY_OPTIMIZED_PATH}
  debug ${QT_CORE_LIBRARY_DEBUG_PATH}
  optimized ${QT_CORE_LIBRARY_OPTIMIZED_PATH}
  debug ${QT_PCRE_LIBRARY_DEBUG_PATH}
  optimized ${QT_PCRE_LIBRARY_OPTIMIZED_PATH})
if(WIN32)
  target_link_libraries(ashkal_tester
    debug ${QT_THEME_LIBRARY_DEBUG_PATH}
    optimized ${QT_THEME_LIBRARY_OPTIMIZED_PATH}
    debug ${QT_FREETYPE_LIBRARY_DEBUG_PATH}
    optimized ${QT_FREETYPE_LIBRARY_OPTIMIZED_PATH}
    debug ${QT_MAIN_LIBRARY_DEBUG_PATH}
    optimized ${QT_MAIN_LIBRARY_OPTIMIZED_PATH}
    debug ${QT_WINDOWS_ACCESSIBILITY_LIBRARY_DEBUG_PATH}
    optimized ${QT_WINDOWS_ACCESSIBILITY_LIBRARY_OPTIMIZED_PATH}
    debug ${QT_WINDOWS_LIBRARY_DEBUG_PATH}
    optimized ${QT_WINDOWS_LIBRARY_OPTIMIZED_PATH}
    imm32.lib winmm.lib ws2_32.lib opengl32.lib version.lib netapi32.lib
    userenv.lib dwmapi.lib)
endif()
if(UNIX)
  target_link_libraries(ashkal_tester
    debug ${QT_EDID_LIBRARY_DEBUG_PATH}
    optimized ${QT_EDID_LIBRARY_OPTIMIZED_PATH}
    debug ${QT_XCB_PLATFORM_LIBRARY_DEBUG_PATH}
    optimized ${QT_XCB_PLATFORM_LIBRARY_OPTIMIZED_PATH}
    debug ${QT_XCB_PLUGIN_LIBRARY_DEBUG_PATH}
    optimized ${QT_XCB_PLUGIN_LIBRARY_OPTIMIZED_PATH}
    debug ${QT_XCB_LIBRARY_DEBUG_PATH}
    optimized ${QT_XCB_LIBRARY_OPTIMIZED_PATH}
    dbus-1 dl fontconfig freetype glib-2.0 ICE double-conversion pthread rt SM
    X11 X11-xcb xcb Xi xkbcommon xkbcommon-x11 Xrender)
endif()
install(TARGETS ashkal_tester
  DESTINATION ${CMAKE_CURRENT_SOURCE_DIR}/../../Tests)
