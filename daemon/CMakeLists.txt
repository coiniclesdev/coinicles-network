set(EXE coiniclesnet)
set(EXE_SRC main.cpp)
set(CTL coiniclesnetctl)
set(CTL_SRC coiniclesnetctl.cpp)

if(TRACY_ROOT)
    list(APPEND EXE_SRC ${TRACY_ROOT}/TracyClient.cpp)
endif()

if(SHADOW)
    set(COINICLESNET_SHADOW shadow-plugin-${SHARED_LIB})
    set(COINICLESNET_SHADOW_LIBS ${SHARED_LIB})
    add_shadow_plugin(${COINICLESNET_SHADOW} ${EXE_SRC})
    target_link_libraries(${COINICLESNET_SHADOW} ${COINICLESNET_SHADOW_LIBS})
    target_include_directories(${COINICLESNET_SHADOW} PUBLIC ${PROJECT_SOURCE_DIR}/include ${PROJECT_SOURCE_DIR}/llarp ${PROJECT_SOURCE_DIR}/crypto/include)
else()
    if(WIN32 AND NOT MSVC_VERSION)
        list(APPEND EXE_SRC ../llarp/win32/version.rc)
        list(APPEND CTL_SRC ../llarp/win32/version.rc)
    endif()

    add_executable(${EXE} ${EXE_SRC})
    add_executable(${CTL} ${CTL_SRC})

    target_compile_definitions(${EXE} PRIVATE -DVERSIONTAG=${GIT_VERSION_REAL})
    target_compile_definitions(${CTL} PRIVATE -DVERSIONTAG=${GIT_VERSION_REAL})

    add_log_tag(${EXE})
    add_log_tag(${CTL})

    install(TARGETS ${EXE} RUNTIME DESTINATION bin COMPONENT coiniclesnet)
    if(WIN32)
        install(PROGRAMS ${CMAKE_SOURCE_DIR}/coiniclesnet-bootstrap.ps1 DESTINATION bin COMPONENT coiniclesnet)
    else()
        install(PROGRAMS ${CMAKE_SOURCE_DIR}/coiniclesnet-bootstrap DESTINATION bin COMPONENT coiniclesnet)
    endif()

    if(${CMAKE_SYSTEM_NAME} MATCHES "Linux")
        install(CODE "execute_process(COMMAND setcap cap_net_admin,cap_net_bind_service=+eip ${CMAKE_INSTALL_PREFIX}/bin/coiniclesnet)")
    elseif(${CMAKE_SYSTEM_NAME} MATCHES "FreeBSD")
        target_link_directories(${EXE} PRIVATE /usr/local/lib)
        target_link_directories(${CTL} PRIVATE /usr/local/lib)
    endif()
    target_link_libraries(${EXE} PUBLIC ${EXE_LIBS} ${LIBS} ${CRYPTOGRAPHY_LIB})
    target_link_libraries(${CTL} PUBLIC ${EXE_LIBS} ${LIBS} ${CRYPTOGRAPHY_LIB})

    if(CURL_FOUND)
        target_include_directories(${CTL} PRIVATE ${CURL_INCLUDE_DIRS})
        target_link_libraries(${CTL} PRIVATE ${CURL_LIBRARIES})
        target_compile_definitions(${CTL} PRIVATE -DWITH_CURL=1)
    endif(CURL_FOUND)

endif(SHADOW)
