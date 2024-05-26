

int linearSearch(int deck[], int size, int target) { // find index of a card return 99 if card not found
    for (int i = 0; i < size; i++) {
        if (deck[i] == target) {
            return i; // return the index of the found element
        }
    }
    return 99; // return 99 if the element is not found
}
