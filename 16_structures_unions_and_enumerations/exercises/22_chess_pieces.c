int main(void) {
  enum chess_pieces {KING, QUEEN, ROOK, BISHOP, KNIGHT, PAWN};

  // a)
  const int piece_value[] = {200, 9, 5, 3, 3, 1};

  // b)
  const int piece_value2[] = {
    [KING] = 200,
    [QUEEN] = 9,
    [ROOK] = 5,
    [BISHOP] = 3,
    [KNIGHT] = 3,
    [PAWN] = 1,
  };

  return 0;
}
