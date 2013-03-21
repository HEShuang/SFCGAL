#-- configure tests
set( SFCGAL_TEST_DIRECTORY "${CMAKE_SOURCE_DIR}/test" )
configure_file( ${SFCGAL_TEST_DIRECTORY}/test_config.h.cmake ${SFCGAL_TEST_DIRECTORY}/test_config.h )

if ( SFCGAL_BUILD_TEST )
	#-- build unit tests
	add_subdirectory( unit )
	#-- build regression tests
	add_subdirectory( regress )
endif()

if( SFCGAL_BUILD_BENCH )
	add_subdirectory( bench )
endif()



