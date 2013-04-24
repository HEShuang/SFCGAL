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
#ifndef _SFCGAL_TRANSFORM_AFFINETRANSFORM3_H_
#define _SFCGAL_TRANSFORM_AFFINETRANSFORM3_H_

#include <CGAL/Aff_transformation_3.h>
#include <SFCGAL/Transform.h>

namespace SFCGAL {
namespace transform {

	/**
	 * Wrapper for CGAL::Aff_transform_3
	 */
	template < typename K >
	class AffineTransform3 : public Transform {
	public:
		/**
		 * Constructor with a transform
		 */
		AffineTransform3( CGAL::Aff_transformation_3< Kernel > transform ):
			_transform(transform)
		{

		}

		/*
		 * [SFCGAL::Transform]
		 */
		virtual void transform( Coordinate & c )
		{
			c = Coordinate( c.toPoint_3().transform( _transform ) ) ;
		}

	private:
		CGAL::Aff_transformation_3< K > _transform ;
	};


}//transform
}//SFCGAL




#endif

