mod ChessBoardLib;

use ChessBoardLib as cbl;

fn main() {
    println!("Hello, world!");
    unsafe
    {
        // TODO: make the user enter sides
        cbl::DrawChessboard(6, 8);
    }
}
