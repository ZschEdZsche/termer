#ifndef TERMER_CHARS_H
#define TERMER_CHARS_H

#define CHAR_LEN 25
#define CHAR_W 5
#define CHAR_H 5

char colon[CHAR_H][CHAR_W] = {
    { ' ', ' ', ' ', ' ', ' ' },
    { ' ', ' ', 'O', ' ', ' ' },
    { ' ', ' ', ' ', ' ', ' ' },
    { ' ', ' ', 'O', ' ', ' ' },
    { ' ', ' ', ' ', ' ', ' ' }
};

char numbers[10][CHAR_H][CHAR_W] = {
    {
        { ' ', '0', '0', '0', ' ' },
        { '0', ' ', ' ', '0', '0' },
        { '0', ' ', '0', ' ', '0' },
        { '0', '0', ' ', ' ', '0' },
        { ' ', '0', '0', '0', ' ' }
    },
    {
        { ' ', '1', '1', ' ', ' ' },
        { '1', '1', '1', ' ', ' ' },
        { ' ', '1', '1', ' ', ' ' },
        { ' ', '1', '1', ' ', ' ' },
        { '1', '1', 'l', '1', ' ' }
    },
    {
        { ' ', '2', '2', ' ', ' ' },
        { '2', ' ', ' ', '2', ' ' },
        { ' ', ' ', '2', ' ', ' ' },
        { ' ', '2', ' ', ' ', ' ' },
        { '2', '2', '2', '2', ' ' }
    },
    {
        { '3', '3', '3', ' ', ' ' },
        { ' ', ' ', ' ', '3', ' ' },
        { ' ', '3', '3', ' ', ' ' },
        { ' ', ' ', ' ', '3', ' ' },
        { '3', '3', '3', ' ', ' ' }
    },
    {
        { '4', ' ', ' ', '4', ' ', },
        { '4', ' ', ' ', '4', ' ', },
        { '4', '4', '4', '4', ' ', },
        { ' ', ' ', ' ', '4', ' ', },
        { ' ', ' ', ' ', '4', ' ', }
    },
    {
        { '5', '5', '5', '5', ' ', },
        { '5', ' ', ' ', ' ', ' ', },
        { '5', '5', '5', ' ', ' ', },
        { ' ', ' ', ' ', '5', ' ', },
        { '5', '5', '5', ' ', ' ', }
    },
    {
        { ' ', ' ', '6', ' ', ' ', },
        { ' ', '6', ' ', ' ', ' ', },
        { '6', '6', '6', '6', ' ', },
        { '6', ' ', ' ', ' ', '6', },
        { ' ', '6', '6', '6', ' ', }
    },
    {
        { '7', '7', '7', '7', '7', },
        { ' ', ' ', ' ', '7', ' ', },
        { ' ', ' ', ' ', '7', ' ', },
        { ' ', ' ', '7', ' ', ' ', },
        { ' ', ' ', '7', ' ', ' ', }
    },
    {
        { ' ', '8', '8', '8', ' ', },
        { '8', ' ', ' ', ' ', '8', },
        { ' ', '8', '8', '8', ' ', },
        { '8', ' ', ' ', ' ', '8', },
        { ' ', '8', '8', '8', ' ', }
    },
    {
        { ' ', '9', '9', '9', '9', },
        { '9', ' ', ' ', ' ', '9', },
        { ' ', '9', '9', '9', '9', },
        { ' ', ' ', ' ', '9', ' ', },
        { ' ', ' ', '9', ' ', ' ', }
    }
};


#endif
