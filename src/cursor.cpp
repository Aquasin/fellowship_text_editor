#include "cursor.hpp"

Cursor::Cursor() {
    this->col = 0;
    this->row = 0;
}

void Cursor::move_cursor(int col, int row) {
    this->col = col;
    this->row = row;
}

void Cursor::set_offsets(float x, float y) {
    x_offset = x;
    y_offset = y;
}

int Cursor::get_col() {
    return this->col;
}

int Cursor::get_row() {
    return this->row;
}

float Cursor::get_x_offset() {
    return x_offset;
}

float Cursor::get_y_offset() {
    return y_offset;
}