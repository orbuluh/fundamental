class TicTacToe:

    def __init__(self, n: int):
        self.row = [0] * n
        self.col = [0] * n
        self.diag = 0
        self.rev_diag = 0

    def move(self, r: int, c: int, player: int) -> int:
        score = 1 if player == 1 else -1
        self.row[c] += score
        self.col[r] += score
        if r == c:
            self.diag += score
        n = len(self.row)
        if r == n - 1 - c:
            self.rev_diag += score
        if any(
            [abs(x) == n for x in [self.row[c], self.col[r], self.diag, self.rev_diag]]
        ):
            return player
        return 0
