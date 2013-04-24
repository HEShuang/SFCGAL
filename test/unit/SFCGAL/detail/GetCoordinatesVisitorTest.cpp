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
#include <boost/test/unit_test.hpp>

#include <SFCGAL/all.h>
#include <SFCGAL/detail/GetCoordinatesVisitor.h>


using namespace SFCGAL ;
using namespace SFCGAL::detail ;

// always after CGAL
using namespace boost::unit_test ;


BOOST_AUTO_TEST_SUITE( SFCGAL_detail_GetCoordinateVisitorTest )

//Interval() ;
BOOST_AUTO_TEST_CASE( testNotSharedButEqual )
{
	LineString ring ;
	ring.addPoint( Point(0.0,0.0) );
	ring.addPoint( Point(1.0,1.0) );
	ring.addPoint( Point(2.0,2.0) );
	ring.addPoint( Point(0.0,0.0) );

	std::set< SharedCoordinate > coordinates ;
	GetCoordinatesVisitor visitor( coordinates ) ;
	ring.accept( visitor );
	BOOST_CHECK_EQUAL( coordinates.size(), 4U );
}

//Interval() ;
BOOST_AUTO_TEST_CASE( testSharedButEqual )
{
	LineString ring ;
	ring.addPoint( Point(0.0,0.0) );
	ring.addPoint( Point(1.0,1.0) );
	ring.addPoint( Point(2.0,2.0) );
	ring.addPoint( ring.startPoint() );

	std::set< SharedCoordinate > coordinates ;
	GetCoordinatesVisitor visitor( coordinates ) ;
	ring.accept( visitor );
	BOOST_CHECK_EQUAL( coordinates.size(), 3U );
}


BOOST_AUTO_TEST_SUITE_END()

