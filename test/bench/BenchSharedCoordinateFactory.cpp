/**
 *   SFCGAL
 *
 *   Copyright (C) 2012-2013 Oslandia <infos@oslandia.com>
 *   Copyright (C) 2012-2013 IGN (http://www.ign.fr)
 *
 *   This program is free software: you can redistribute it and/or modify
 *   it under the terms of the GNU General Public License as published by
 *   the Free Software Foundation, either version 3 of the License, or
 *   (at your option) any later version.
 *
 *   This program is distributed in the hope that it will be useful,
 *   but WITHOUT ANY WARRANTY; without even the implied warranty of
 *   MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
 *   GNU General Public License for more details.
 *
 *   You should have received a copy of the GNU General Public License
 *   along with this program.  If not, see <http://www.gnu.org/licenses/>.
 *
 */
#include <SFCGAL/all.h>
#include <SFCGAL/SharedCoordinateFactory.h>

#include "../test_config.h"
#include "Bench.h"

#include <boost/test/unit_test.hpp>


using namespace boost::unit_test ;
using namespace SFCGAL ;

BOOST_AUTO_TEST_SUITE( SFCGAL_BenchSharedCoordinateFactory )

BOOST_AUTO_TEST_CASE( testCreateWithout )
{
	bench().start( "[SharedCoordinateFactory]create 1000000 points without factory" ) ;
	for ( int i = 0; i < 1000000; i++ ){
		SharedCoordinate sharedCoordinate( new Coordinate( i, i ) ) ;
		BOOST_CHECK_EQUAL( sharedCoordinate->x(), i );
		BOOST_CHECK_EQUAL( sharedCoordinate->y(), i );
	}
	bench().stop();
}

BOOST_AUTO_TEST_CASE( testCreateUnique )
{
	SharedCoordinateFactory factory ;

	bench().start( "[SharedCoordinateFactory]create 1000000 points with factory" ) ;
	for ( int i = 0; i < 1000000; i++ ){
		SharedCoordinate sharedCoordinate = factory.makeSharedCoordinate( i, i ) ;
		BOOST_CHECK_EQUAL( sharedCoordinate->x(), i ) ;
		BOOST_CHECK_EQUAL( sharedCoordinate->y(), i ) ;
	}
	bench().stop();
}

BOOST_AUTO_TEST_CASE( testCreateDuplicate )
{
	SharedCoordinateFactory factory ;

	bench().start( "[SharedCoordinateFactory]create 1000000 points with duplicates" ) ;
	for ( int i = 0; i < 1000000; i++ ){
		SharedCoordinate sharedCoordinate = factory.makeSharedCoordinate( i % 2, i % 3 ) ;
		BOOST_CHECK_EQUAL( sharedCoordinate->x(), i % 2 ) ;
		BOOST_CHECK_EQUAL( sharedCoordinate->y(), i % 3 ) ;
	}
	bench().stop();
}

BOOST_AUTO_TEST_SUITE_END()






//BOOST_AUTO_TEST_CASE( testTemp ){
//	std::auto_ptr< Geometry > gA( io::readWkt("MULTIPOLYGON(((11.795461 32.713032,11.381695 35.857648,15.188336 38.091981,28.428825 38.257487,30.994170 33.788822,30.580405 29.816675,26.773764 22.617159,11.050683 18.562259,-0.534745 21.044851,-3.513855 26.837565,3.520155 26.506553,4.099426 24.685985,4.678698 22.782665,6.582018 21.541369,8.899104 21.458616,16.098620 21.706875,18.332952 25.016998,17.919187 27.499589,16.429632 27.830601,14.360805 26.175540,13.036756 24.520479,10.885177 23.527442,8.733597 23.527442,6.002747 24.603232,4.595945 26.506553,1.203069 27.830601,1.368575 30.892465,2.113353 34.202587,4.678698 36.519672,6.664771 36.188660,8.071573 34.699105,7.409549 32.630279,5.837240 31.968254,5.919993 30.064934,7.575055 28.740885,10.802424 27.582342,12.126473 27.913355,13.781534 28.740885,14.443558 29.816675,14.691818 31.306230,14.278052 33.126797,13.450522 34.119834,11.795461 32.713032),(21.477568 36.188660,15.684854 36.271413,14.609065 28.161614,15.022830 27.582342,20.401779 29.816675,29.339109 32.133760,21.477568 36.188660)))") );
//	std::auto_ptr< Geometry > gB( io::readWkt( "POLYGON((-1 0,0 -1,1 0,0 1,-1 0))" ) );
//
//	std::auto_ptr< Geometry > sum( algorithm::minkowskiSum( *gA, gB->as< Polygon >() ) );
//	std::cout << sum->asText(6) << std::endl ;
//}
