#ifndef MAP_PART_H
#define MAP_PART_H


class map_part
{
    public:
        map_part();
        int get_pixel(int x, int y);
        virtual ~map_part();
    protected:
    private:
};

#endif // MAP_PART_H
