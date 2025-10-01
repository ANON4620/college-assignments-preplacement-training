int towerOfHanoi(int n, int from, int to, int aux) {
    if (n == 0) return 0;
    int moves = towerOfHanoi(n - 1, from, aux, to);
    moves += 1;
    moves += towerOfHanoi(n - 1, aux, to, from);
    return moves;
}
