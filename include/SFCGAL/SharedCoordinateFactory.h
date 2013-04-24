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
#ifndef _SFCGAL_SHAREDCOORDINATEFACTORY_H_
#define _SFCGAL_SHAREDCOORDINATEFACTORY_H_

#include <set>

#include <SFCGAL/Coordinate.h>
#include <SFCGAL/Kernel.h>
#include <SFCGAL/Geometry.h>

#include <SFCGAL/detail/LessSharedPtr.h>

namespace SFCGAL {

	/**
	 * @brief helper class to create 2D and 3D unique SharedCoordinate
	 *
	 * @warning do not mix 2D and 3D creation
	 */
	class SharedCoordinateFactory {
	public:

		/**
		 * @brief XY Constructor with exact coordinates
		 */
		SharedCoordinate makeSharedCoordinate( const Coordinate & c ) ;


		template < typename T >
		inline SharedCoordinate makeSharedCoordinate( const T& x, const T& y ){
			return makeSharedCoordinate( Coordinate(x,y) );
		}

		template < typename T >
		inline SharedCoordinate makeSharedCoordinate( const T& x, const T& y, const T& z ){
			return makeSharedCoordinate( Coordinate(x,y,z) );
		}

		/**
		 * @brief clear existing coordinates
		 */
		void clear() ;

	private:
		std::set< SharedCoordinate, detail::LessSharedPtr > _coordinates ;
	};

} // namespace SFCGAL


#endif

