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
#include <SFCGAL/PointVisitor.h>
#include <SFCGAL/all.h>

namespace SFCGAL {

///
///
///
PointVisitor::~PointVisitor()
{

}

///
///
///
void PointVisitor::visit( LineString & g )
{
	for ( LineString::iterator it = g.begin(); it != g.end(); ++it ){
		visit( *it );
	}
}

///
///
///
void PointVisitor::visit( Polygon & g )
{
	for ( Polygon::iterator it = g.begin(); it != g.end(); ++it ){
		visit( *it );
	}
}

///
///
///
void PointVisitor::visit( Triangle & g )
{
	for ( size_t i = 0; i < 3; i++ ){
		visit( g.vertex(i) );
	}
}

///
///
///
void PointVisitor::visit( Solid & g )
{
	for ( Solid::iterator it = g.begin(); it != g.end(); ++it ){
		visit( *it ) ;
	}
}


///
///
///
void PointVisitor::visit( MultiPoint & g )
{
	for ( MultiPoint::iterator it = g.begin(); it != g.end(); ++it ){
		visit( it->as< Point >() ) ;
	}
}

///
///
///
void PointVisitor::visit( MultiLineString & g )
{
	for ( MultiLineString::iterator it = g.begin(); it != g.end(); ++it ){
		visit( it->as< LineString >() ) ;
	}
}

///
///
///
void PointVisitor::visit( MultiPolygon & g )
{
	for ( MultiPolygon::iterator it = g.begin(); it != g.end(); ++it ){
		visit( it->as< Polygon >() ) ;
	}
}

///
///
///
void PointVisitor::visit( MultiSolid & g )
{
	for ( MultiSolid::iterator it = g.begin(); it != g.end(); ++it ){
		visit( it->as< Solid >() ) ;
	}
}


///
///
///
void PointVisitor::visit( GeometryCollection & g )
{
	for ( GeometryCollection::iterator it = g.begin(); it != g.end(); ++it ){
		GeometryVisitor::visit( *it ) ;
	}
}

///
///
///
void PointVisitor::visit( PolyhedralSurface & g )
{
	for ( PolyhedralSurface::iterator it = g.begin(); it != g.end(); ++it ){
		visit( *it ) ;
	}
}


///
///
///
void PointVisitor::visit( TriangulatedSurface & g )
{
	for ( TriangulatedSurface::iterator it = g.begin(); it != g.end(); ++it ){
		visit( *it ) ;
	}
}


///-------------- CONST



///
///
///
ConstPointVisitor::~ConstPointVisitor()
{

}

///
///
///
void ConstPointVisitor::visit( const LineString & g )
{
	for ( LineString::const_iterator it = g.begin(); it != g.end(); ++it ){
		visit( *it );
	}
}

///
///
///
void ConstPointVisitor::visit( const Polygon & g )
{
	for ( Polygon::const_iterator it = g.begin(); it != g.end(); ++it ){
		visit( *it );
	}
}

///
///
///
void ConstPointVisitor::visit( const Triangle & g )
{
	for ( size_t i = 0; i < 3; i++ ){
		visit( g.vertex(i) );
	}
}

///
///
///
void ConstPointVisitor::visit( const Solid & g )
{
	for ( Solid::const_iterator it = g.begin(); it != g.end(); ++it ){
		visit( *it ) ;
	}
}


///
///
///
void ConstPointVisitor::visit( const MultiPoint & g )
{
	for ( MultiPoint::const_iterator it = g.begin(); it != g.end(); ++it ){
		visit( it->as< Point >() ) ;
	}
}

///
///
///
void ConstPointVisitor::visit( const MultiLineString & g )
{
	for ( MultiLineString::const_iterator it = g.begin(); it != g.end(); ++it ){
		visit( it->as< LineString >() ) ;
	}
}

///
///
///
void ConstPointVisitor::visit( const MultiPolygon & g )
{
	for ( MultiPolygon::const_iterator it = g.begin(); it != g.end(); ++it ){
		visit( it->as< Polygon >() ) ;
	}
}

///
///
///
void ConstPointVisitor::visit( const MultiSolid & g )
{
	for ( MultiSolid::const_iterator it = g.begin(); it != g.end(); ++it ){
		visit( it->as< Solid >() ) ;
	}
}


///
///
///
void ConstPointVisitor::visit( const GeometryCollection & g )
{
	for ( GeometryCollection::const_iterator it = g.begin(); it != g.end(); ++it ){
		ConstGeometryVisitor::visit( *it ) ;
	}
}

///
///
///
void ConstPointVisitor::visit( const PolyhedralSurface & g )
{
	for ( PolyhedralSurface::const_iterator it = g.begin(); it != g.end(); ++it ){
		visit( *it ) ;
	}
}


///
///
///
void ConstPointVisitor::visit( const TriangulatedSurface & g )
{
	for ( TriangulatedSurface::const_iterator it = g.begin(); it != g.end(); ++it ){
		visit( *it ) ;
	}
}





} // namespace SFCGAL




