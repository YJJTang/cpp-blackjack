target_sources(${PROJECT_NAME}
        PRIVATE
        dealer.cc
        player.cc
        PUBLIC
        dealer.h
        player.h
        )

target_include_directories(${PROJECT_NAME}
        PUBLIC
        ${CMAKE_CURRENT_LIST_DIR}
        )