typedef struct PAIR {
    Integer i, j;
    Integer distance;
} PAIR;

PAIR* PAIR_Create(Integer i, Integer j, Integer distance) {
    PAIR *new_pair = (PAIR*) malloc(sizeof(PAIR));
    new_pair->i = i;
    new_pair->j = j;
    new_pair->distance = distance;
    return new_pair;
}

bool PAIR_Is_Lower(PAIR *first, PAIR *second) {
    if(first->distance < second->distance) {
        return true;
    }
    return false;
}

bool PAIR_Is_Bigger(PAIR *first, PAIR *second) {
    if(first->distance > second->distance) {
        return true;
    }
    return false;
}
