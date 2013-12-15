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
    if ((x < 220) || (x>420))
        return ((x/2 + y/2) % 2 ? 0x00000000 : ((y / 32) % 2 ? 0x00FF00FF : 0x0000FFFF));
    return ((x/2 + y/2) % 2 ? 0xFFFFFFFF : 0x00000000);
}
