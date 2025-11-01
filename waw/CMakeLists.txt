add_executable(world_at_war
    src/main.cpp
    src/game.cpp
)

target_include_directories(world_at_war PRIVATE ${CMAKE_CURRENT_SOURCE_DIR}/include)

target_link_libraries(world_at_war PRIVATE
    SFML::Graphics
    SFML::Audio
)

target_compile_features(world_at_war PRIVATE cxx_std_20)
set_target_properties(world_at_war PROPERTIES RUNTIME_OUTPUT_DIRECTORY ${CMAKE_BINARY_DIR}/bin)

add_custom_command(TARGET world_at_war POST_BUILD
COMMAND ${CMAKE_COMMAND} -E make_directory $<TARGET_FILE_DIR:world_at_war>/assets
COMMAND ${CMAKE_COMMAND} -E copy_directory
${CMAKE_CURRENT_SOURCE_DIR}/assets
$<TARGET_FILE_DIR:world_at_war>/assets
VERBATIM)

target_compile_definitions(world_at_war PRIVATE ASSETS_DIR="${CMAKE_CURRENT_SOURCE_DIR}/assets")