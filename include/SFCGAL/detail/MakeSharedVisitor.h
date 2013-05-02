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
#ifndef _SFCGAL_DETAIL_MAKESHAREDVISITOR_H_
#define _SFCGAL_DETAIL_MAKESHAREDVISITOR_H_

#include <set>

#include <SFCGAL/PointVisitor.h>
#include <SFCGAL/SharedCoordinateFactory.h>


namespace SFCGAL {
namespace detail {

	/**
	 * @brief rebuild coordinate sharing in a geometry
	 */
	class MakeSharedVisitor : public PointVisitor {
	public:
		/**
		 * @brief visit a point
		 */
		virtual void visit( Point & g ) ;
	private:
		SharedCoordinateFactory _factory ;
	};

} // namespace detail
} // namespace SFCGAL



#endif

