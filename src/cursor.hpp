#ifndef CURSOR_HPP
#define CURSOR_HPP

class Cursor {
private:
    float x_offset, y_offset;
    int col, row;

public:
    Cursor();

    // setters
    void move_cursor(int col, int row);
    void set_offsets(float x, float y);

    // getters
    int get_col();
    int get_row();
    float get_x_offset();
    float get_y_offset();

};

#endif /* CURSOR_HPP */