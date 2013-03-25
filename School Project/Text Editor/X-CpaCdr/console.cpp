#include "console.h"

namespace cio {

    using namespace bio;

    unsigned int CIO_TABSIZE = 4;
    Console console;

    Console::Console() {
    }

    void Console::_insert(char* str, int key, int length, int maxLength, int* offset, int* position, bool insertMode) {
        if (strlen(str) < maxLength) {
            if (insertMode) {
                for (int i = maxLength + 1; i >= *offset + *position; i--) {
                    str[i] = str[i - 1];
                }
            }
            if (strlen(str) == *offset + *position) {
                str[*offset + *position + 1] = 0;
            }
            str[*offset + *position] = key;
            if (maxLength > *offset + *position + 1) {
                if (length > *position + 1) {
                    (*position)++;
                }
                else {
                    (*offset)++;
                }
            }
        }
    }

    void Console::display(const char* str, int row, int col, int length) {
        for (int i = 0; !length ? *str : (i < length); !i++ ? setPos(row, col) : void() , putChar(*str ? *str++ : ' '));
    }

    int Console::edit(char* str, int row, int col, int length, int maxLength, bool* insertMode, int* offset, int* position, bool textEditor, bool readOnly){
        bool done = false;
        bool tempInsertMode = *insertMode;
        char* temp = new char[strlen(str) + 1];
        int key = 0;
        int tempOffset = *offset;
        int tempPosition = *position;

        if (*offset > strlen(str)) {
            *offset = strlen(str);
        }
        if (*position > strlen(str)) {
            *position = strlen(str);
        }
        if (*position > length) {
            *position = length - 1;
        }

        if (textEditor) {
            if (*offset != tempOffset) {
                done = true;
                key = 0;
            }
        }

        strcpy(temp, str);
        while (!done) {
            display(str + *offset, row, col, length);
            setPos(row, col + *position);
            switch (key = getKey()) {
                case INSERT:
                    *insertMode = !(*insertMode);
                break;
                case HOME:
                    *offset = *position = 0;
                break;
                case END:
                    if (strlen(str) - *offset < length) {
                        *position = strlen(str) - *offset;
                    }
                    else {
                        *offset = strlen(str) - length + 1;
                        *position = length - 1;
                    }
                break;
                case LEFT:
                    if (*position) {
                        (*position)--;
                    }
                    else if (*offset) {
                        (*offset)--;
                    }
                break;
                case RIGHT:
                    if (*position + *offset < strlen(str)) {
                        if (*position + 1 < length) {
                            (*position)++;
                        }
                        else if (*offset + *position < maxLength - 1) {
                            (*offset)++;
                        }
                    }
                break;
                case DEL:
                    for (int i = *position + *offset; str[i]; i++) {
                        str[i] = str[i + 1];
                    }
                break;
                case BACKSPACE:
                    if (*position + *offset) {
                        for (int i = *position + *offset; str[i]; i++) {
                            str[i] = str[i + 1];
                        }
                        if (*position) {
                            (*position)--;
                        }
                        else if (*offset) {
                            (*offset)--;
                        }
                    }
                break;
                case ESCAPE:
                    done = true;
                break;
                case TAB:
                    if (textEditor) {
                        for (int i = 0; i < CIO_TABSIZE; i++) {
                            _insert(str, SPACE, length, maxLength, offset, position, *insertMode);
                        }
                    }
                    else {
                        done = true;
                    }
                break;
                default:
                    if (key >= 32 && key <= 126) {
                        _insert(str, key, length, maxLength, offset, position, *insertMode);
                    }
                    else {
                        done = true;
                    }
                break;
            }
            if (textEditor) {
                if (tempOffset != *offset) {
                    done = true;
                    key = 0;
                }
            }
        }

        if ((!textEditor && key == ESCAPE) || readOnly) {
            if (key == ESCAPE) {
                *offset = tempOffset;
                *position = tempPosition;
            }
            strcpy(str, temp);
        }

        delete [] temp;
        return key;
    }

    Console& operator>>(Console& console, int& character) {
        character = console.getKey();
        return console;
    }

    Console& operator<<(Console& console, char character) {
        console.putChar(character);
        return console;
    }

    Console& operator<<(Console& console, const char* str) {
        while (*str) {
            console << *str++;
        }
        return console;
    }

}
