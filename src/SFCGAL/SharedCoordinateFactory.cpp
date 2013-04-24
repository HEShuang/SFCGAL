#include <SFCGAL/SharedCoordinateFactory.h>

namespace SFCGAL {

///
///
///
SharedCoordinate SharedCoordinateFactory::makeSharedCoordinate( const Coordinate & c )
{
	SharedCoordinate sc( new Coordinate( c ) );
	std::map< Coordinate, SharedCoordinate >::iterator it = _coordinates.find( *sc ) ;
	if ( it != _coordinates.end() ){
		return it->second ;
	}else{
		_coordinates.insert( std::make_pair( *sc, sc ) );
		return sc ;
	}
}


///
///
///
void SharedCoordinateFactory::clear()
{
	_coordinates.clear() ;
}


} // namespace SFCGAL



