set(TEST_MAIN blackjack_test)

add_subdirectory(card_properties)

add_executable(
        ${TEST_MAIN}
        ${CARD_PROPERTIES}
)

target_include_directories(${TEST_MAIN}
        PRIVATE
        ${CMAKE_SOURCE_DIR}/src/card_properties
        ${CMAKE_SOURCE_DIR}/src/game_participants
        )

target_link_libraries(
        ${TEST_MAIN}
        GTest::gtest_main
)

include(GoogleTest)
gtest_discover_tests(${TEST_MAIN})