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
#ifndef _SFCGAL_POINTVISITOR_H_
#define _SFCGAL_POINTVISITOR_H_

#include <SFCGAL/GeometryVisitor.h>

namespace SFCGAL {

	/**
	 * visitor a point
	 */
	class PointVisitor : public GeometryVisitor {
	public:
		virtual ~PointVisitor() ;

		virtual void visit( Point & g ) = 0 ;

		virtual void visit( LineString & g ) ;
		virtual void visit( Polygon & g ) ;
		virtual void visit( Triangle & g ) ;
		virtual void visit( Solid & g ) ;
		virtual void visit( MultiPoint & g ) ;
		virtual void visit( MultiLineString & g ) ;
		virtual void visit( MultiPolygon & g ) ;
		virtual void visit( MultiSolid & g ) ;
		virtual void visit( GeometryCollection & g ) ;
		virtual void visit( PolyhedralSurface & g ) ;
		virtual void visit( TriangulatedSurface & g ) ;
	};



	/**
	 * visitor a point
	 */
	class ConstPointVisitor : public ConstGeometryVisitor {
	public:
		virtual ~ConstPointVisitor() ;

		virtual void visit( const Point & g ) = 0 ;

		virtual void visit( const LineString & g ) ;
		virtual void visit( const Polygon & g ) ;
		virtual void visit( const Triangle & g ) ;
		virtual void visit( const Solid & g ) ;
		virtual void visit( const MultiPoint & g ) ;
		virtual void visit( const MultiLineString & g ) ;
		virtual void visit( const MultiPolygon & g ) ;
		virtual void visit( const MultiSolid & g ) ;
		virtual void visit( const GeometryCollection & g ) ;
		virtual void visit( const PolyhedralSurface & g ) ;
		virtual void visit( const TriangulatedSurface & g ) ;
	};



} // namespace SFCGAL



#endif

