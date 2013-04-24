#include <SFCGAL/SharedCoordinateFactory.h>

namespace SFCGAL {

///
///
///
SharedCoordinate SharedCoordinateFactory::makeSharedCoordinate( const Coordinate & c )
{
	typedef std::set< SharedCoordinate, detail::LessSharedPtr >::iterator iterator ;

	SharedCoordinate sc( new Coordinate( c ) );
	std::pair< iterator, bool > result = _coordinates.insert( sc );
	return *result.first ;
}


///
///
///
void SharedCoordinateFactory::clear()
{
	_coordinates.clear() ;
}


} // namespace SFCGAL



