#include "../include/map_part.h"

map_part::map_part()
{
    //ctor
}

map_part::~map_part()
{
    //dtor
}

int map_part::get_pixel(int x, int y)
{
    if ((x < 270) || (x>370))
        return ((x+y) % 2 ? 0x00000000 : ((y / 32) % 2 ? 0x00FF00FF : 0x0000FFFF));
    return 0xFFFFFFFF;
}
