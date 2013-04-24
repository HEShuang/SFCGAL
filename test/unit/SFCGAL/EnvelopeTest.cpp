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

#include <SFCGAL/Envelope.h>

using namespace boost::unit_test ;
using namespace SFCGAL ;

BOOST_AUTO_TEST_SUITE( SFCGAL_EnvelopeTest )

//Envelope() ;
BOOST_AUTO_TEST_CASE( defaultConstructor )
{
	Envelope box ;
	BOOST_CHECK( box.boundsN(0).isEmpty() );
	BOOST_CHECK( box.boundsN(1).isEmpty() );
	BOOST_CHECK( box.boundsN(2).isEmpty() );
}

//Envelope( const Coordinate & p ) ;
BOOST_AUTO_TEST_CASE( constructorWithCoordinateXY )
{
	Envelope box( Coordinate(1.0,2.0) );
	BOOST_CHECK( box.boundsN(0) == detail::Interval(1.0) );
	BOOST_CHECK( box.boundsN(1) == detail::Interval(2.0) );
	BOOST_CHECK( box.boundsN(2).isEmpty() );
}

//Envelope( const Coordinate & p1, const Coordinate & p2 ) ;
BOOST_AUTO_TEST_CASE( constructorWithTwoCoordinateXY )
{
	Envelope box( Coordinate(3.0,5.0), Coordinate(1.0,2.0) );
	BOOST_CHECK( box.boundsN(0) == detail::Interval(1.0,3.0) );
	BOOST_CHECK( box.boundsN(1) == detail::Interval(2.0,5.0) );
	BOOST_CHECK( box.boundsN(2).isEmpty() );
}

//Envelope( const Envelope& other ) ;
//Envelope& operator = ( const Envelope& other ) ;
//~Envelope() ;

//bool isEmpty() const ;
BOOST_AUTO_TEST_CASE( testIsEmpty )
{
	Envelope box ;
	BOOST_CHECK( box.isEmpty() );
}
BOOST_AUTO_TEST_CASE( testIsNotEmpty )
{
	Envelope box( Coordinate(0.0,0.0) ) ;
	BOOST_CHECK( ! box.isEmpty() );
}
//bool is3D() const ;
BOOST_AUTO_TEST_CASE( testIs3D )
{
	Envelope box( Coordinate(0.0,0.0,0.0) ) ;
	BOOST_CHECK( box.is3D() );
}
BOOST_AUTO_TEST_CASE( testNotIs3D )
{
	Envelope box( Coordinate(0.0,0.0) ) ;
	BOOST_CHECK( ! box.is3D() );
}
//void expandToInclude( const Coordinate & coordinate ) ;

BOOST_AUTO_TEST_CASE( testExpandToInclude )
{
	Envelope box ;
	BOOST_CHECK( box.isEmpty() );

	box.expandToInclude( Coordinate(0.0,0.0) ) ;
	BOOST_CHECK( ! box.isEmpty() );
	BOOST_CHECK( ! box.is3D() );

	BOOST_CHECK( box.boundsN(0) == detail::Interval(0.0) );
	BOOST_CHECK( box.boundsN(1) == detail::Interval(0.0) );

	box.expandToInclude( Coordinate(0.0,0.0,0.0) ) ;
	BOOST_CHECK( ! box.isEmpty() );
	BOOST_CHECK( box.is3D() );

	BOOST_CHECK( box.boundsN(0) == detail::Interval(0.0) );
	BOOST_CHECK( box.boundsN(1) == detail::Interval(0.0) );
	BOOST_CHECK( box.boundsN(2) == detail::Interval(0.0) );

	box.expandToInclude( Coordinate(1.0,2.0) ) ;
	BOOST_CHECK( box.boundsN(0) == detail::Interval(0.0,1.0) );
	BOOST_CHECK( box.boundsN(1) == detail::Interval(0.0,2.0) );
	BOOST_CHECK( box.boundsN(2) == detail::Interval(0.0) );
}

BOOST_AUTO_TEST_CASE( testAsText_empty )
{
	Envelope box;
	BOOST_CHECK_EQUAL( box.asText(), "" );
}
BOOST_AUTO_TEST_CASE( testAsTexte_2d )
{
	Envelope box(Coordinate(0,1),Coordinate(2,3));
	BOOST_CHECK_EQUAL( box.asText(1), "BOX(0.0 1.0,2.0 3.0)");
}
BOOST_AUTO_TEST_CASE( testAsTexte_3d )
{
	Envelope box(Coordinate(0,1,2),Coordinate(3,4,5));
	BOOST_CHECK_EQUAL( box.asText(1), "BOX3D(0.0 1.0 2.0,3.0 4.0 5.0)");
}

BOOST_AUTO_TEST_SUITE_END()




